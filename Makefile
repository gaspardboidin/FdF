# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 16:22:17 by gaboidin          #+#    #+#              #
#    Updated: 2025/02/21 20:57:09 by gaboidin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src
BONUSDIR = bonus
OBJDIR = obj
LIBFTDIR = libft
MLXDIR = /home/gaboidin/42/minilibx/minilibx-linux

# Détection de l'OS
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLX = -L$(MLXDIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
	INCLUDES = -I$(MLXDIR) -I$(LIBFTDIR) -Iincludes
else
	MLX = -lmlx -framework OpenGL -framework AppKit
	INCLUDES = -Imlx -I$(LIBFTDIR) -Iincludes
endif

# Pour EXTRA_FLAGS, on utilisera -DBONUS uniquement si BONUS_FLAG est défini.
ifeq ($(BONUS_FLAG),1)
	EXTRA_FLAGS = -DBONUS
else
	EXTRA_FLAGS =
endif

SRCS = $(SRCDIR)/main.c \
	   $(SRCDIR)/init.c \
	   $(SRCDIR)/event.c \
	   $(SRCDIR)/parse_map.c \
	   $(SRCDIR)/parse_map_utils.c \
	   $(SRCDIR)/draw.c \
	   $(SRCDIR)/math.c \
	   $(SRCDIR)/projection.c \
	   $(SRCDIR)/rotation.c \
	   $(SRCDIR)/maping.c \
	   $(SRCDIR)/maping2.c \
	   $(SRCDIR)/cleanup.c

SRCS_BONUS = $(BONUSDIR)/altitude_bonus.c \
			 $(BONUSDIR)/color_bonus.c \
			 $(BONUSDIR)/move_bonus.c \
			 $(BONUSDIR)/rotate_map_bonus.c \
			 $(BONUSDIR)/zoom_bonus.c

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
ifeq ($(BONUS_FLAG),1)
	OBJS_BONUS = $(SRCS_BONUS:$(BONUSDIR)/%.c=$(OBJDIR)/%.o)
else
	OBJS_BONUS =
endif

LIBFT = $(LIBFTDIR)/libft.a

RM = rm -rf
MKDIR = mkdir -p

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFTDIR) --no-print-directory

# Compilation des fichiers de src/ avec EXTRA_FLAGS
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(LIBFT)
	@$(MKDIR) $(OBJDIR)
	@$(CC) $(CFLAGS) $(EXTRA_FLAGS) $(INCLUDES) -c $< -o $@

# Compilation des fichiers bonus (avec EXTRA_FLAGS)
$(OBJDIR)/%.o: $(BONUSDIR)/%.c | $(LIBFT)
	@$(MKDIR) $(OBJDIR)
	@$(CC) $(CFLAGS) $(EXTRA_FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(OBJS_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(OBJS_BONUS) $(LIBFT) $(MLX) -o $(NAME)
	@echo "✅ Compilation terminée !"

# Pour la cible bonus, on force BONUS_FLAG et EXTRA_FLAGS
bonus:
	@$(MAKE) -s fclean BONUS_FLAG=1 EXTRA_FLAGS=-DBONUS
	@$(MAKE) -s all BONUS_FLAG=1 EXTRA_FLAGS=-DBONUS
	@echo "✅ Compilation bonus terminée !"


clean:
	@$(RM) $(OBJDIR)
	@make clean -C $(LIBFTDIR) --no-print-directory
	@echo "🗑️  Objets supprimés."

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFTDIR) --no-print-directory
	@echo "🗑️  Exécutable supprimé."

re: fclean all

.PHONY: all bonus clean fclean re

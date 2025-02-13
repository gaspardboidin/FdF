# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaboidin <gaboidin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 17:10:11 by gaboidin          #+#    #+#              #
#    Updated: 2025/01/30 16:39:22 by gaboidin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de la librairie
NAME = libft.a

# Fichiers sources
SRCS =	src/ft_isalnum.c src/ft_isprint.c src/ft_memcmp.c src/ft_putchar_fd.c src/ft_split.c \
		src/ft_strlcat.c src/ft_strncmp.c src/ft_substr.c src/ft_atoi.c src/ft_isalpha.c \
		src/ft_itoa.c src/ft_memcpy.c src/ft_putendl_fd.c src/ft_strchr.c src/ft_strlcpy.c \
		src/ft_strnstr.c src/ft_tolower.c src/ft_bzero.c src/ft_isascii.c \
		src/ft_memmove.c src/ft_putnbr_fd.c src/ft_strdup.c src/ft_strlen.c src/ft_strrchr.c \
		src/ft_toupper.c src/ft_calloc.c src/ft_isdigit.c src/ft_memchr.c src/ft_memset.c  \
		src/ft_putstr_fd.c src/ft_strjoin.c src/ft_strmapi.c src/ft_strtrim.c src/ft_striteri.c \
		printf/ft_printf.c printf/utils/ft_handler.c printf/utils/ft_handler2.c printf/utils/ft_parser.c \
		get-next-line/get_next_line.c

# Fichiers objets
OBJS = $(SRCS:.c=.o)

# Compilateur
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Nettoyage
RM = rm -f

# Couleurs pour un affichage propre
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

# Règle
all: $(NAME)

# Compilation de la librairie
$(NAME): $(OBJS)
		@echo "$(YELLOW)Compilation de la librairie...$(NAME)$(RESET)"
		@ar rcs $(NAME) $(OBJS)
		@echo "$(GREEN)Compilation terminée !$(RESET)"

# Compilation des fichiers objets avec affichage propre
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
		@echo "$(YELLOW)Nettoyage des fichiers objets...$(RESET)"
		@$(RM) $(OBJS)

# Suppression de la librairie
fclean: clean
		@echo "$(YELLOW)Suppression de $(NAME)...$(RESET)"
		@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
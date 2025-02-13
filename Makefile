# 🛠 Nom de l'exécutable
NAME = fdf

# 🏗️ Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# 📁 Dossiers
SRCDIR = src
OBJDIR = obj
LIBFTDIR = libft

# 📜 Fichiers sources
SRCS =  $(SRCDIR)/main.c \
        $(SRCDIR)/init.c \
        $(SRCDIR)/event_handler.c \
		$(SRCDIR)/event_handler_2.c \
        $(SRCDIR)/parse_map.c \
		$(SRCDIR)/parse_map_utils.c \
        $(SRCDIR)/draw.c \
		$(SRCDIR)/math.c \
		$(SRCDIR)/projection.c \
		$(SRCDIR)/rotation.c \

# 🏗️ Générer les fichiers objets
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# 🏗️ Librairies
LIBFT = $(LIBFTDIR)/libft.a
MLX = -lmlx -framework OpenGL -framework AppKit

# 🛠 Commandes
RM = rm -rf
MKDIR = mkdir -p

# 🔧 Règle principale : compilation de `FdF`
all: $(NAME)

# 📦 Compilation de `libft` uniquement si `libft.a` n'existe pas
$(LIBFT):
	@make -C $(LIBFTDIR) --no-print-directory

# 🎯 Compilation des fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(LIBFT)
	@$(MKDIR) $(OBJDIR)
	@$(CC) $(CFLAGS) -Imlx -I$(LIBFTDIR) -c $< -o $@

# 🚀 Compilation de l'exécutable `fdf`
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
	@echo "✅ Compilation terminée !"

# 🧹 Nettoyage des objets
clean:
	@$(RM) $(OBJDIR)
	@make clean -C $(LIBFTDIR) --no-print-directory
	@echo "🗑️  Objets supprimés."

# 🧹 Nettoyage complet
fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFTDIR) --no-print-directory
	@echo "🗑️  Exécutable supprimé."

# 🔄 Recompiler proprement
re: fclean all

# 📌 Indiquer que ce ne sont pas des fichiers
.PHONY: all clean fclean re

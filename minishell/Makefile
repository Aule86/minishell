# NAME = minishell
# CC = gcc
# FLAGS = -Wall -Wextra -Werror
# LIBFT_DIR = libft/
# LIBFT = $(LIBFT_DIR)libft.a

# SRC = 	minishell.c \
# 		execute_command.c \
# 		parse_command.c \
# 		read_command.c \
# 		init_shell.c \
# 		env_command.c \



# .SILENT:


# $(NAME):
# 	echo "Compilando..."
# 	make -C $(LIBFT_DIR) all clean
# 	$(CC) $(FLAGS) $(SRC) $(LIBFT) -Iincludes -o $(NAME)

# all: $(NAME)


# clean:
# 	@rm -rf *.o
# 	make -C $(LIBFT_DIR) fclean

# fclean: clean
# 	@rm -rf ${NAME}

# re: fclean all

# .PHONY : all clean fclean re
NAME = minishell
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRC = 	minishell.c \
		execute_command.c \
		parse_command.c \
		read_command.c \
		init_shell.c \
		env_command.c \

OBJ = $(SRC:.c=.o)

.SILENT:

$(NAME): $(OBJ) $(LIBFT)
	echo "Compilando..."
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -Iincludes -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) all

all: $(NAME)

clean:
	@rm -rf *.o
	make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
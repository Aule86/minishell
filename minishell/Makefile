NAME = minishell
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
# READLINE #
READLINE_PREFIX = /usr/local/opt/readline
LDFLAGS = -lreadline -L$(READLINE_PREFIX)/lib
READLINE = -I$(READLINE_PREFIX)/include
#LINUX_READLINE = -lreadline -L/usr/lib/x86_64-linux-gnu/

SRC = 	minishell.c \
		execute_command.c \
		parse_command.c \
		read_command.c \
		init_shell.c \
		env_command.c \
		process_command.c \
		signal.c \
		ft_envp.c \

OBJ = $(SRC:.c=.o)

.SILENT:

$(NAME): $(OBJ) $(LIBFT)
	echo "Compilando..."
	$(CC) $(FLAGS) $(LDFLAGS) $(READLINE) $(OBJ) $(LIBFT) -Iincludes -o $(NAME)

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

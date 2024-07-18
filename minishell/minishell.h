/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyra <cyra@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:00:20 by aule86            #+#    #+#             */
/*   Updated: 2024/07/17 13:24:12 by cyra             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

# define BUFFER_SIZE 1024

typedef struct s_shell
{
	char	buffer[BUFFER_SIZE]; //
	char	**argv; // copia de los argumentos
	char	**envp; // variables de entorno
	char	**env_copy;// copia variables de entorno
}			t_shell;

void	init_shell(t_shell *shell, char **envp);
void	read_command(t_shell *shell);
char	**parse_command(char *buffer);
void	execute_command(t_shell *shell);
void	handle_signal(int signal);
void	setup_shell(t_shell *shell, char **envp);
void	env_command(t_shell *shell);

#endif

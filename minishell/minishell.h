/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule86 <aule86@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:00:20 by aule86            #+#    #+#             */
/*   Updated: 2024/08/01 12:00:31 by aule86           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
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
void	setup_shell(t_shell *shell, char **envp);
void	env_command(t_shell *shell);
int		check_spaces(char *c);
void	cleanup_shell(t_shell *shell);
void	process_command(t_shell *shell);
char	**ft_env_strdup(char **envp);
//señales
//void	wait_signal(int signal);

#endif

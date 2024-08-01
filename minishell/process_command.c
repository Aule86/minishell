/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule86 <aule86@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:28:06 by aule86            #+#    #+#             */
/*   Updated: 2024/08/01 12:05:48 by aule86           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* void	setup_shell(t_shell *shell, char **envp)
{
	shell->envp = ft_env_strdup(envp);
	init_shell(shell, envp);
	signal(SIGINT, wait_signal);
} */

void	handle_signal(int signal)
{
	if (signal == SIGINT)
		write(STDOUT_FILENO, "\nminishell> ", 12);
}

void	setup_shell(t_shell *shell, char **envp)
{
	shell->envp = envp;
	init_shell(shell, envp);
	signal(SIGINT, handle_signal);
}

void	process_command(t_shell *shell)
{
	if (ft_strncmp(shell->buffer, "exit", 4) == 0
		&& shell->buffer[4] == '\0')
		exit(0);
	shell->argv = parse_command(shell->buffer);
	if (shell->argv[0] != NULL)
	{
		if (ft_strncmp(shell->argv[0], "env", 3) == 0
			&& shell->argv[0][3] == '\0')
			env_command(shell);
		else
			execute_command(shell);
	}
	free(shell->argv);
}
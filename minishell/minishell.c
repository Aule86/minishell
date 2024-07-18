/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyra <cyra@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:24:27 by aule86            #+#    #+#             */
/*   Updated: 2024/07/18 13:50:44 by cyra             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	cleanup_shell(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->env_copy[i] != NULL)
	{
		free(shell->env_copy[i]);
		i++;
	}
	free(shell->env_copy);
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

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char *input;

	input = NULL;

	(void)argc;
	(void)argv;
	setup_shell(&shell, envp);
	while (1)
	{
		input = readline("minishell>");
		if(input == NULL);
			break ;
		//check si tiene espacios  o si porlomenos tenga mas de 1 charater
		if(check_spaces(input) == -1 || input[0] == '\0')
		{
			free(input);
			continue ;
		}
		//read_command(&shell);
		process_command(&shell);
	}
	cleanup_shell(&shell);
	return (0);
}

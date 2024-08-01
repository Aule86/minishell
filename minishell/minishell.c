/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule86 <aule86@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:24:27 by aule86            #+#    #+#             */
/*   Updated: 2024/08/01 12:24:12 by aule86           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*input;

	input = NULL;
	(void)argc;
	(void)argv;
	setup_shell(&shell, envp);
	while (1)
	{
		input = readline("minishell>");
		if (input == NULL)
			break ;
		//read_command(&shell);
		process_command(&shell);
		//check si tiene espacios  o si porlomenos tenga mas de 1 charater
		if (check_spaces(input) == -1 || input[0] == '\0')
		{
			free(input);
			printf("");
		}
		//historial
		add_history(input);
	}
	cleanup_shell(&shell);
	return (0);
}

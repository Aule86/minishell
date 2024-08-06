/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule86 <aule86@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:18:39 by aule86            #+#    #+#             */
/*   Updated: 2024/08/05 11:13:45 by aule86           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_command(t_shell *shell, char *line)
{
	//line = readline("minishell>");
	if (line)
	{
		if (*line)
			add_history(line);
		ft_strlcpy(shell->buffer, line, BUFFER_SIZE);
	}
	else
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}
}

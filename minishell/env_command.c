/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyra <cyra@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:16:10 by aule86            #+#    #+#             */
/*   Updated: 2024/07/18 13:49:46 by cyra             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// mira que haya algun charater que no sdea espacio
int check_spaces(char *c)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (c[++i])
	{
		if (c[i] == '\t' || c[i] == '\n'
			|| c[i] == '\v' || c[i] == '\f'
			|| c[i] == '\r' || c[i] == ' ')
			j++;
	}
	if (j == i)
		return (-1);
	return (0);
}


//copia y guarda en variable el env
void	env_command(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->env_copy[i] != NULL)
	{
		printf("%s\n", shell->env_copy[i]);
		i++;
	}
}
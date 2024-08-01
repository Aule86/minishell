/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule86 <aule86@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:02:06 by aule86            #+#    #+#             */
/*   Updated: 2024/08/01 12:14:06 by aule86           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//copia el envp todas las variables menos la de oldpwd

char	**ft_env_copy(char **envp)
{
	char	**envp_copy;
	int		i;

	i = 0;
	envp_copy = (char **)malloc(sizeof(char *) * (ft_newstrlen(envp) + 1));
	if (!envp_copy)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "OLDPWD=", 7))
		{
			envp_copy[i] = ft_strdup(envp[i]);
			i++;
		}
	}
	envp_copy[i] = NULL;
	return (envp_copy);
}

//busca el oldpwd y lo guarda en una variable
// de no ser asi llama a la funcion de copiar el env
char	**ft_env_strdup(char **envp)
{
	char	**envp_c;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "OLDPWD=", 7))
		{
			envp_c = (char **)malloc(sizeof(char *) * (ft_newstrlen(envp) + 1));
			if (!envp_c)
				return (NULL);
			i = 0;
			while (envp[i])
			{
				envp_c[i] = ft_strdup(envp[i]);
				i++;
			}
			envp_c[i] = NULL;
			return (envp_c);
		}
	}
	envp_c = ft_env_copy(envp);
	return (envp_c);
}

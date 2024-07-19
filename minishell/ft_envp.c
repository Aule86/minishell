/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule86 <aule86@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:02:06 by aule86            #+#    #+#             */
/*   Updated: 2024/07/19 11:22:36 by aule86           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	envp_c = ft_envp_copy(envp);
	return (envp_c);
}
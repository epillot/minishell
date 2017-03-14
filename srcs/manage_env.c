/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 12:52:29 by epillot           #+#    #+#             */
/*   Updated: 2017/03/10 17:44:08 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_new_env(char *name, char *val, char ***env)
{
	char	**new_env;
	int		i;
	size_t size;

	i = 0;
	while ((*env)[i])
		i++;
	size = sizeof(char*) * (i + 1);
	if (!(new_env = ft_realloc(*env, size, size + sizeof(char*))))
		minishell_error(MALLOC, 0, NULL, NULL);
	if (!(new_env[i] = ft_strjoin(name, val)))
		minishell_error(MALLOC, 0, NULL, NULL);
	*env = new_env;
}

void		manage_env(char *name, char *newval, char ***env)
{
	char **target;

	if ((target = ft_getenv(name, *env)) != NULL)
	{
		free(*target);
		if (!(*target = ft_strjoin(name, newval)))
			minishell_error(MALLOC, 0, NULL, NULL);
	}
	else
		get_new_env(name, newval, env);
}

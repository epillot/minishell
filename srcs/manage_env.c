/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 12:52:29 by epillot           #+#    #+#             */
/*   Updated: 2017/03/14 16:26:14 by epillot          ###   ########.fr       */
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
	if (ft_sprintf(new_env + i, "%s=%s", name, val) == -1)
		minishell_error(MALLOC, 0, NULL, NULL);
	*env = new_env;
}

void		manage_env(char *name, char *newval, char ***env)
{
	char **target;

	if ((target = ft_getenv(name, *env)) != NULL)
	{
		free(*target);
		if (ft_sprintf(target, "%s=%s", name, newval) == -1)
			minishell_error(MALLOC, 0, NULL, NULL);
	}
	else
		get_new_env(name, newval, env);
}

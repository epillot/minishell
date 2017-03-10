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

static void	get_new_env(char *var, char *val, char ***env)
{
	char	**new_env;
	int		i;

	i = 0;
	while ((*env)[i])
		i++;
	if (!(new_env = (char**)ft_memalloc(sizeof(char*) * (i + 2))))
		minishell_error(MALLOC, 0, NULL, NULL);
	i = 0;
	while ((*env)[i])
	{
		if (!(new_env[i] = ft_strdup((*env)[i])))
			minishell_error(MALLOC, 0, NULL, NULL);
		i++;
	}
	if (!(new_env[i] = ft_strjoin(var, val)))
		minishell_error(MALLOC, 0, NULL, NULL);
	ft_strtab_free(*env);
	*env = new_env;
}

void		manage_env(char *var, char *newval, char ***env)
{
	int		i;

	i = 0;
	if (!*env)
		return ;
	while ((*env)[i] && ft_strncmp((*env)[i], var, ft_strlen(var)) != 0)
		i++;
	if ((*env)[i])
	{
		//ft_putendl((*env)[i]); //
		free((*env)[i]);
		if (!((*env)[i] = ft_strjoin(var, newval)))
			minishell_error(MALLOC, 0, NULL, NULL);
	}
	else
		get_new_env(var, newval, env);
}

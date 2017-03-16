/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:55:16 by epillot           #+#    #+#             */
/*   Updated: 2017/03/16 13:59:21 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	add_in_env(char *param, char ***env)
{
	char	*name;
	int		i;

	i = 0;
	while (param[i] != '=')
		i++;
	if (i == 0)
	{
		ft_printf_fd(2, "minishell: env: setenv %s: Invalid argument\n", param);
		return (0);
	}
	if (!(name = ft_strnew(sizeof(char) * i)))
		minishell_error(MALLOC, 0, NULL, NULL);
	ft_strncpy(name, param, i);
	manage_env(name, param + i + 1, env);
	free(name);
	return (1);
}

static char	**get_new_env(char ***cmd, char **env)
{
	char	**out;

	if (**cmd && ft_strcmp(**cmd, "-i") == 0)
	{
		if (!(out = ft_memalloc(sizeof(char*))))
			minishell_error(MALLOC, 0, NULL, NULL);
		(*cmd)++;
	}
	else
	{
		if (!(out = ft_strtab_dup(env)))
			minishell_error(MALLOC, 0, NULL, NULL);
	}
	while (**cmd && ft_strchr(**cmd, '=') != NULL)
	{
		if (!(add_in_env(**cmd, &out)))
		{
			ft_strtab_free(out);
			return (NULL);
		}
		(*cmd)++;
	}
	return (out);
}

static void	print_env(char **env)
{
	while (*env)
		ft_putendl(*env++);
}

void		ft_env(char **cmd, char **env)
{
	char	**tmpenv;

	if (!(tmpenv = get_new_env(&cmd, env)))
		return ;
	if (*cmd)
		exec_cmd_env(cmd, &tmpenv);
	else
		print_env(tmpenv);
	ft_strtab_free(tmpenv);
}

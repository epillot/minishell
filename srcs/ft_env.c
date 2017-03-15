/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:55:16 by epillot           #+#    #+#             */
/*   Updated: 2017/03/15 18:43:27 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_env_var(char *param)
{
	while (*param)
	{
		if (*param == '=')
			return (1);
		param++;
	}
	return (0);
}

static int	add_in_env(char *param, char ***env)
{
	char	*name;
	int		i;

	i = 0;
	while (param[i] != '=')
		i++;
	if (i == 0)
	{
		ft_printf_fd(2, "env: setenv %s: Invalid argument\n", param);
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
	while (**cmd && is_env_var(**cmd))
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
	char	**tmpcmd;

	if (!(tmpenv = get_new_env(&cmd, env)))
		return ;
	if (*cmd)
	{
		if (!(tmpcmd = ft_strtab_dup(cmd)))
			minishell_error(MALLOC, 0, NULL, NULL);
		process_cmd(tmpcmd, &tmpenv);
//		exec_cmd_env(cmd, tmpenv);
	}
	else
		print_env(tmpenv);
	ft_strtab_free(tmpenv);
}

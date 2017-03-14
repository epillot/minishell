/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:50:06 by epillot           #+#    #+#             */
/*   Updated: 2017/03/14 17:06:43 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char **get_bin_path(char **env)
{
	char	**path;
	int		i;

	i = 0;
	path = ft_getenv("PATH", env);
	if (path)
	{
		while ((*path)[i] != '=')
			i++;
		if (!(path = ft_strsplit(*path + i + 1, ':')))
			minishell_error(MALLOC, 0, NULL, NULL);
	}
	else
	{
		if (!(path = ft_strsplit("", ':')))
			minishell_error(MALLOC, 0, NULL, NULL);
	}
	return (path);
}

static int	check_access(char *path, char *cmd)
{
	if (access(path, F_OK) == 0)
	{
		if (access(path, X_OK) == 0)
			return (1);
		else
		{
			minishell_error(MY_EACCESS, 0, NULL, cmd);
			return (0);
		}
	}
	return (-1);
}

int			get_cmd_path(char *cmd, char **env, char **cmd_path)
{
	int		i;
	int		acc;
	char	**bin_path;

	i = -1;
	bin_path = get_bin_path(env);
	while (bin_path[++i])
	{
		if (ft_sprintf(cmd_path, "%s/%s", bin_path[i], cmd) == -1)
			minishell_error(MALLOC, 0, NULL, NULL);
		ft_putendl(*cmd_path);
		if ((acc = check_access(*cmd_path, cmd)) == 1)
		{
			ft_strtab_free(bin_path);
			return (1);
		}
		else if (!acc)
		{
			ft_strtab_free(bin_path);
			return (0);
		}
		free(*cmd_path);
	}
	*cmd_path = NULL;
	ft_putendl("la");
	minishell_error(CMDNOTFOUND, 0, NULL, cmd);
	ft_strtab_free(bin_path);
	return (0);
}

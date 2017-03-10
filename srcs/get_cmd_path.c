/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:50:06 by epillot           #+#    #+#             */
/*   Updated: 2017/03/09 12:52:24 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int			get_cmd_path(char **bin_path, char *cmd, char **cmd_path)
{
	int		i;
	int		acc;

	i = -1;
	while (bin_path[++i])
	{
		if (ft_sprintf(cmd_path, "%s/%s", bin_path[i], cmd) == -1)
			minishell_error(MALLOC, 0, NULL, NULL);
		if ((acc = check_access(*cmd_path, cmd)) == 1)
			return (1);
		else if (!acc)
			return (0);
		free(*cmd_path);
	}
	*cmd_path = NULL;
	minishell_error(CMDNOTFOUND, 0, NULL, cmd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:59:41 by epillot           #+#    #+#             */
/*   Updated: 2017/03/08 18:44:38 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_path(char *cmd)
{
	while (*cmd)
	{
		if (*cmd == '/')
			return (1);
		cmd++;
	}
	return (0);
}

static int	get_cmd_path(char **bin_path, char *cmd, char **cmd_path)
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
	minishell_error(MY_ENOENT, 0, NULL, cmd);
	return (0);
}

static void	exec_cmd(char *cmd_path, char **cmd, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd_path, cmd, env) == -1)
		{
			minishell_error(MY_ENOENT, 0, NULL, *cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
}

void		process_cmd(char **bin_path, char *line, char **env)
{
	char		**cmd;
	char		*cmd_path;
	struct stat	buf;

	if (!(cmd = ft_strsplit(line, ' ')))
		minishell_error(MALLOC, 0, NULL, NULL);
	if (is_path(*cmd))
	{
		if (lstat(*cmd, &buf) != -1)
		{
			if (S_ISDIR(buf.st_mode))
				minishell_error(MY_EISDIR, 0, NULL, *cmd);
			else
			{
				if (access(*cmd, X_OK) == 0)
					exec_cmd(*cmd, cmd, env);
				else
					minishell_error(MY_EACCESS, 0, NULL, *cmd);
			}
		}
		else
		{
			ft_putstr("im here\n");
			check_error_path(*cmd, 0, NULL);
		}
	}
	else
	{
		if (get_cmd_path(bin_path, *cmd, &cmd_path) == 1)
			exec_cmd(cmd_path, cmd, env);
		if (cmd_path)
			free(cmd_path);
	}
	ft_strtab_free(cmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:59:41 by epillot           #+#    #+#             */
/*   Updated: 2017/03/10 16:46:01 by epillot          ###   ########.fr       */
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

static int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	return (0);
}

static void	run_cmd(char *cmd_path, char **cmd, char ***env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd_path, cmd, *env) == -1)
		{
			minishell_error(CMDNOTFOUND, 0, NULL, *cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
}

void		process_cmd(char **bin_path, char *line, char ***env)
{
	char		**cmd;
	char		*cmd_path;
	struct stat	buf;

	if (!(cmd = ft_strsplit(line, ' ')))
		minishell_error(MALLOC, 0, NULL, NULL);
	if (!*cmd)
	{
		ft_strtab_free(cmd);
		return ;
	}
	if (is_builtin(*cmd))
		ft_cd(cmd[1], env);
	else if (is_path(*cmd))
	{
		if (stat(*cmd, &buf) != -1)
		{
			if (S_ISDIR(buf.st_mode))
				minishell_error(MY_EISDIR, 0, NULL, *cmd);
			else
			{
				if (access(*cmd, X_OK) == 0)
					run_cmd(*cmd, cmd, env);
				else
					minishell_error(MY_EACCESS, 0, NULL, *cmd);
			}
		}
		else
		{
			//ft_putstr("im here\n");
			check_error_path(*cmd, 0, NULL);
		}
	}
	else
	{
		//ft_putstr("la\n");
		if (get_cmd_path(bin_path, *cmd, &cmd_path) == 1)
			run_cmd(cmd_path, cmd, env);
		if (cmd_path)
			free(cmd_path);
	}
	ft_strtab_free(cmd);
}

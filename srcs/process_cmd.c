/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:59:41 by epillot           #+#    #+#             */
/*   Updated: 2017/03/16 16:44:00 by epillot          ###   ########.fr       */
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
		return (CD);
	if (ft_strcmp(cmd, "setenv") == 0)
		return (SETENV);
	if (ft_strcmp(cmd, "unsetenv") == 0)
		return (UNSETENV);
	if (ft_strcmp(cmd, "echo") == 0)
		return (ECHO);
	if (ft_strcmp(cmd, "env") == 0)
		return (ENV);
	return (0);
}

static void	exec_builtin(int built, char **cmd, char ***env)
{
	if (built == CD)
		ft_cd(*(cmd + 1), env);
	else if (built == SETENV)
		ft_setenv(cmd + 1, env);
	else if (built == UNSETENV)
		ft_unsetenv(cmd + 1, *env);
	else if (built == ECHO)
		ft_echo(cmd + 1, *env);
	else if (built == ENV)
		ft_env(cmd + 1, *env);
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

void		process_cmd(char **cmd, char ***env)
{
	char		*cmd_path;
	struct stat	buf;
	int			built;
	int			err;

	if (!*cmd)
	{
		ft_strtab_free(cmd);
		return ;
	}
	if ((built = is_builtin(*cmd)))
		exec_builtin(built, cmd, env);
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
			err = check_error_path(*cmd);
			minishell_error(err, 0, NULL, *cmd);
		}
	}
	else
	{
		if ((err = get_cmd_path(*cmd, *env, &cmd_path)) == -1)
			run_cmd(cmd_path, cmd, env);
		else
			minishell_error(err, 0, NULL, *cmd);
		if (cmd_path)
			free(cmd_path);
	}
	ft_strtab_free(cmd);
}

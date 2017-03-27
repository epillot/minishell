/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:59:41 by epillot           #+#    #+#             */
/*   Updated: 2017/03/17 14:26:55 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (CD);
	if (ft_strcmp(cmd, "setenv") == 0)
		return (SETENV);
	if (ft_strcmp(cmd, "unsetenv") == 0)
		return (UNSETENV);
	if (ft_strcmp(cmd, "echo") == 0)
		return (MYECHO);
	if (ft_strcmp(cmd, "env") == 0)
		return (ENV);
	if (ft_strcmp(cmd, "exit") == 0)
		return (EXIT);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (PWD);
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
	else if (built == MYECHO)
		ft_echo(cmd + 1, *env);
	else if (built == ENV)
		ft_env(cmd + 1, *env);
	else if (built == PWD)
		ft_pwd();
	else if (built == EXIT)
	{
		ft_strtab_free(cmd);
		ft_strtab_free(*env);
		ft_putendl("exit");
		exit(EXIT_SUCCESS);
	}
}

static void	run_cmd(char *cmd_path, char **cmd, char ***env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd_path, cmd, *env) == -1)
		{
			minishell_error(CMDNOTFOUND, NULL, *cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
}

static void	process_path(char **cmd, char ***env)
{
	struct stat	buf;
	int			err;

	if (stat(*cmd, &buf) != -1)
	{
		if (S_ISDIR(buf.st_mode))
			minishell_error(MY_EISDIR, NULL, *cmd);
		else
		{
			if (access(*cmd, X_OK) == 0)
				run_cmd(*cmd, cmd, env);
			else
				minishell_error(MY_EACCESS, NULL, *cmd);
		}
	}
	else
	{
		err = check_error_path(*cmd);
		minishell_error(err, NULL, *cmd);
	}
}

void		process_cmd(char **cmd, char ***env)
{
	char		*cmd_path;
	int			built;
	int			err;

	if (!*cmd)
	{
		ft_strtab_free(cmd);
		return ;
	}
	if ((built = is_builtin(*cmd)))
		exec_builtin(built, cmd, env);
	else if (ft_strchr(*cmd, '/') != NULL)
		process_path(cmd, env);
	else
	{
		if ((err = get_cmd_path(*cmd, *env, &cmd_path)) == -1)
			run_cmd(cmd_path, cmd, env);
		else
			minishell_error(err, NULL, *cmd);
		if (cmd_path)
			free(cmd_path);
	}
	ft_strtab_free(cmd);
}

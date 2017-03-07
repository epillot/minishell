/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:59:41 by epillot           #+#    #+#             */
/*   Updated: 2017/03/07 19:31:50 by epillot          ###   ########.fr       */
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

static int	check_error_path(char *path)
{
	char		**file;
	int			i;

	if (ft_strlen(path) >= PATH_MAX)
	{
		ft_printf_fd(2, "minishell: %s: File name too long\n", path);
		return (0);
	}
	if (!(file = ft_strsplit(path, '/')))
		exit(EXIT_FAILURE);
	i = -1;
	while (file[++i])
	{
		if (ft_strlen(file[i]) > NAME_MAX)
		{
			ft_printf_fd(2, "minishell: %s: File name too long\n", path);
			ft_strtab_free(file);
			return (0);
		}
		if (access(file[i], F_OK) == 0)
		{
			if (access(file[i], X_OK) != 0)
			{
				ft_printf_fd(2, "minishell: %s: Permission denied\n", path);
				ft_strtab_free(file);
				return (0);
			}
		}
		else
		{
			ft_printf_fd(2, "minishell: %s: No such file or directory\n", path);
			ft_strtab_free(file);
			return (0);
		}
	}
	ft_strtab_free(file);
	return (1);
}

static int	get_cmd_path(char **bin_path, char *cmd, char **cmd_path)
{
	int		i;
	int		acc;

	i = -1;
	while (bin_path[++i])
	{
		if (ft_sprintf(cmd_path, "%s/%s", bin_path[i], cmd) == -1)
			exit(EXIT_FAILURE);
		if ((acc = check_access(*cmd_path, cmd)) == 1)
			return (1);
		else if (!acc)
			return (0);
		free(*cmd_path);
	}
	*cmd_path = NULL;
	ft_printf_fd(2, "minishell: command not found: %s\n", cmd);
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
			ft_printf_fd(2, "minishell: command not found: %s\n", *cmd);
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
		exit(EXIT_FAILURE);
	if (is_path(*cmd))
	{
		if (lstat(*cmd, &buf) != -1)
		{
			if (S_ISDIR(buf.st_mode))
				ft_printf_fd(2, "minishell: %s: is a directory\n", *cmd);
			else
			{
				if (access(*cmd, X_OK) == 0)
					exec_cmd(*cmd, cmd, env);
				else
					ft_printf_fd(2, "minishell: %s: Permission denied\n", *cmd);
			}
		}
		else
		{
			if (check_error_path(*cmd) == 1)
				 ft_printf_fd(2, "minishell: %s: No such file or directory\n", *cmd);
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

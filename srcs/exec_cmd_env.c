/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:25:02 by epillot           #+#    #+#             */
/*   Updated: 2017/03/17 17:41:28 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	run_cmd_env(char *cmd_path, char **cmd, char ***env)
{
	pid_t	pid;
	int		err;

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd_path, cmd, *env) == -1)
		{
			err = check_error_path(cmd_path);
			minishell_error(err, 1, "env", *cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
}

void		exec_cmd_env(char **cmd, char ***env)
{
	char	*cmd_path;
	int		err;

	if (ft_strchr(*cmd, '/') != NULL)
		run_cmd_env(*cmd, cmd, env);
	else
	{
		if ((err = get_cmd_path(*cmd, *env, &cmd_path)) == -1)
			run_cmd_env(cmd_path, cmd, env);
		else
		{
			if (err == CMDNOTFOUND)
				err = MY_ENOENT;
			minishell_error(err, 1, "env", *cmd);
		}
		if (cmd_path)
			free(cmd_path);
	}
}

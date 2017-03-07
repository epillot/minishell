/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:30:07 by epillot           #+#    #+#             */
/*   Updated: 2017/03/07 19:02:27 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*static void	run_cmd(char *cmd_path, char **cmd, char **env)
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
	{
		wait(NULL);
		free(cmd_path);
	}
}*/

void		exec_cmd(char **path, char *line, char **env)
{
	char	**cmd;
	char	*cmd_path;
	int		i;
	int		acc;
	pid_t	pid;

	if (!(cmd = ft_strsplit(line, ' ')))
		exit(EXIT_FAILURE);
	i = -1;
	while (path[++i])
	{
		if (ft_sprintf(&cmd_path, "%s/%s", path[i], *cmd) == -1)
			exit(EXIT_FAILURE);
		if ((acc = check_access(cmd_path, *cmd)) == 1)
		{
			ft_printf("access ok for %s\n", cmd_path);
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
			{
				wait(NULL);
				free(cmd_path);
				break ;
			}
		}
		free(cmd_path);
		if (!acc)
			break ;
	}
	if (!path[i])
		ft_printf_fd(2, "minishell: command not found: %s\n", *cmd);
	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:41:02 by epillot           #+#    #+#             */
/*   Updated: 2017/03/03 18:59:12 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**get_env(char **envi)
{
	char	**env;
	int		i;

	i = 0;
	while (envi[i])
		i++;
	env = (char**)malloc(sizeof(char*) * (i + 1));
	i = 0;
	while (envi[i])
	{
		env[i] = ft_strdup(envi[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

static char	**get_cmd_path(char **env)
{
	char **path;

	while (*env && ft_strncmp(*env, "PATH", 4) != 0)
		env++;
	*env += 5;
	path = ft_strsplit(*env, ':');
	return (path);
}

static void	exec_cmd(char **path, char *line, char **env)
{
	char	**cmd;
	char	*cmd_path;
	int		i;
	int		acc;

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
			if (execve(cmd_path, cmd, env) == -1)
			{
				ft_printf("minishell: command not found: %s\n", *cmd);
				free(cmd_path);
				break ;
			}
		}
		free(cmd_path);
		if (!acc)
			break ;
	}
	if (!path[i])
		ft_printf("minishell: command not found: %s\n", *cmd);
	i = 0;
	exit(EXIT_FAILURE);
/*	while (cmd[i])
		free(cmd[i++]);
	free(cmd);*/
/*	while (path[i])
		free(path[i++]);
	free(path);*/

}

int			main(int ac, char **av, char **envi)
{
	char	*line;
	char	**env;
	char	**path;
	pid_t	pid;
	int		i;

	(void)ac;
	(void)av;
	i = 0;
	env = get_env(envi);
	path = get_cmd_path(env);
	while (42)
	{
		ft_putstr("$> ");
		get_next_line(0, &line);
		if (line && *line)
		{
			pid = fork();
			if (pid == 0)
			{
				exec_cmd(path, line, env);
			//	kill(getpid(), SIGTERM);
			}
			else
				wait(NULL);
			free(line);
		}
	}
}

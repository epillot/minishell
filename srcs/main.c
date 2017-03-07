/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:41:02 by epillot           #+#    #+#             */
/*   Updated: 2017/03/07 18:04:32 by epillot          ###   ########.fr       */
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

static char	**get_bin_path(char **env)
{
	char **path;

	while (*env && ft_strncmp(*env, "PATH", 4) != 0)
		env++;
	*env += 5;
	path = ft_strsplit(*env, ':');
	return (path);
}

int			main(int ac, char **av, char **envi)
{
	char	*line;
	char	**env;
	char	**path;
	int		ret;

	(void)ac;
	(void)av;
	env = get_env(envi);
	path = get_bin_path(env);
	while (42)
	{
		ft_putstr("$> ");
		ret = get_next_line(0, &line);
		if (ret != 1)
			break ;
		if (line && *line)
			process_cmd(path, line, env);
		if (line)
			free(line);
	}
	return (ret == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}

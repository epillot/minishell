/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:41:02 by epillot           #+#    #+#             */
/*   Updated: 2017/03/10 18:14:56 by epillot          ###   ########.fr       */
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
	if (!(env = (char**)malloc(sizeof(char*) * (i + 1))))
		minishell_error(MALLOC, 0, NULL, NULL);
	i = 0;
	while (envi[i])
	{
		if (!(env[i] = ft_strdup(envi[i])))
			minishell_error(MALLOC, 0, NULL, NULL);
		i++;
	}
	env[i] = NULL;
	return (env);
}

static char	**get_bin_path(char **env)
{
	char **path;

	while (*env && ft_strncmp(*env, "PATH=", 5) != 0)
		env++;
	if (!(path = ft_strsplit(*env + 5, ':')))
		minishell_error(MALLOC, 0, NULL, NULL);
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
	if (!envi || !*envi)
	{
		ft_putendl("env nul");
		return (0);
	}
	env = get_env(envi);
	path = get_bin_path(env);
	while (42)
	{
		ft_putstr("$> ");
		ret = get_next_line(0, &line);
		if (ret != 1)
			break ;
		if (line && *line)
			process_cmd(path, line, &env);
		if (line)
			free(line);
	}
	return (ret == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}

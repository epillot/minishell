/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 12:28:36 by epillot           #+#    #+#             */
/*   Updated: 2017/03/14 15:56:50 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*read_path(void)
{
	int		fd;
	char	*path;
	char	*tmp;
	int		ret;
	char	*out;

	out = NULL;
	fd = open("/etc/paths", O_RDONLY);
	while ((ret = get_next_line(fd, &path)) == 1)
	{
		if (out)
		{
			tmp = out;
			ft_sprintf(&out, "%s:%s", tmp, path);
			free(tmp);
			free(path);
		}
		else
			out = path;
	}
	if (ret == -1)
		minishell_error(MALLOC, 0, NULL, NULL);
	return (out);
}

char		**minishell_init(char **envi)
{
	char	*val;
	char	**env;
	char	**tmp;
	int		lvl;

	if (!(env = ft_strtab_dup(envi)))
		minishell_error(MALLOC, 0, NULL, NULL);
	if (ft_getenv("PATH", env) == NULL)
	{
		val = read_path();
		manage_env("PATH", val, &env);
		free(val);
	}
	val = getcwd(NULL, 0);
	manage_env("PWD", val, &env);
	free(val);
	tmp = ft_getenv("SHLVL", env);
	if (tmp)
	{
		val = *tmp;
		while (*val != '=')
			val++;
		lvl = ft_atoi(val + 1);
		if (!(val = ft_itoa(lvl + 1)))
			minishell_error(MALLOC, 0, NULL, NULL);
		free(*tmp);
		*tmp = ft_strjoin("SHLVL=", val);
		free(val);
	}
	else
		manage_env("SHLVL", "1", &env);
	return (env);
}

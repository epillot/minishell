/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 12:28:36 by epillot           #+#    #+#             */
/*   Updated: 2017/03/16 16:26:42 by epillot          ###   ########.fr       */
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
			if (ft_sprintf(&out, "%s:%s", tmp, path) == -1)
				minishell_error(MALLOC, NULL, NULL);
			free(tmp);
			free(path);
		}
		else
			out = path;
	}
	if (ret == -1 && fd >= 0)
		minishell_error(MALLOC, NULL, NULL);
	return (out);
}

static void	init_path(char ***env)
{
	char	*val;

	if (ft_getenv("PATH", *env) == NULL)
	{
		val = read_path();
		if (val)
		{
			manage_env("PATH", val, env);
			free(val);
		}
	}
}

static void	init_pwd(char ***env)
{
	char	*val;

	if ((val = getcwd(NULL, 0)) != NULL)
	{
		manage_env("PWD", val, env);
		free(val);
	}
	else
	{
		ft_putstr_fd("shell-init: error retrieving current directory: ", 2);
		ft_putendl_fd("getcwd: cannot access parent directories.", 2);
	}
}

char		**minishell_init(char **envi)
{
	char	*val;
	char	**env;
	char	**tmp;
	int		lvl;

	if (!(env = ft_strtab_dup(envi)))
		minishell_error(MALLOC, NULL, NULL);
	init_path(&env);
	init_pwd(&env);
	tmp = ft_getenv("SHLVL", env);
	if (tmp)
	{
		val = *tmp;
		while (*val != '=')
			val++;
		lvl = ft_atoi(val + 1);
		if (!(val = ft_itoa(lvl + 1)))
			minishell_error(MALLOC, NULL, NULL);
		free(*tmp);
		if (!(*tmp = ft_strjoin("SHLVL=", val)))
			minishell_error(MALLOC, NULL, NULL);
		free(val);
	}
	else
		manage_env("SHLVL", "1", &env);
	return (env);
}

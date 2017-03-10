/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:54:31 by epillot           #+#    #+#             */
/*   Updated: 2017/03/10 16:36:18 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_path_length(char *path, int builtin, char *builtname)
{
	if (ft_strlen(path) >= PATH_MAX)
	{
		minishell_error(MY_ENAMETOOLONG, builtin, builtname, path);
		return (0);
	}
	return (1);
}

static int	check_name_length(int len, char *path, int builtin, char *builtname)
{
	if (len == NAME_MAX + 1)
	{
		minishell_error(MY_ENAMETOOLONG, builtin, builtname, path);
		return (0);
	}
	return (1);
}

static int	check_path_access(char *sub_path, char *path,
		int builtin, char *builtname)
{
	if (access(sub_path, F_OK) == 0)
	{
		if (access(sub_path, X_OK))
		{
			minishell_error(MY_EACCESS, builtin, builtname, path);
			return (0);
		}
		return (1);
	}
	minishell_error(MY_ENOENT, builtin, builtname, path);
	return (0);
}

int			check_error_path(char *path, int builtin, char *builtname)
{
	char	buf[PATH_MAX];
	int		i;
	int		j;
	char	*tmp_path;

	tmp_path = path;
	if (!(check_path_length(path, builtin, builtname)))
		return (0);
	ft_bzero(buf, PATH_MAX);
	i = 0;
	while (*tmp_path)
	{
		j = 0;
		while (*tmp_path && *tmp_path != '/' && ++j <= NAME_MAX)
			buf[i++] = *tmp_path++;
		if (*tmp_path == '/')
			buf[i++] = *tmp_path++;
		if (!(check_name_length(j, path, builtin, builtname)))
			return (0);
		if (!(check_path_access(buf, path, builtin, builtname)))
			return (0);
	}
	return (1);
}

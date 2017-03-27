/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:54:31 by epillot           #+#    #+#             */
/*   Updated: 2017/03/16 18:31:22 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_path_access(char *sub_path)
{
	if (access(sub_path, F_OK) == 0)
	{
		if (access(sub_path, X_OK) != 0)
			return (-1);
		return (1);
	}
	ft_putendl("la");
	return (0);
}

static int	is_dir(char *path)
{
	struct stat	buf;

	if (!*path)
		return (1);
	if (stat(path, &buf) != -1)
	{
		if (!S_ISDIR(buf.st_mode))
			return (0);
		return (1);
	}
	return (0);
}

int			check_error_path(char *path)
{
	char	buf[PATH_MAX];
	int		i;
	int		j;
	int		acc;

	ft_bzero(buf, PATH_MAX);
	i = 0;
	while (*path)
	{
		j = 0;
		if (*path == '/')
		{
			if (!is_dir(buf))
				return (MY_ENOTDIR);
			buf[i++] = *path++;
		}
		while (*path && *path != '/' && ++j <= NAME_MAX)
			buf[i++] = *path++;
		if (j == NAME_MAX + 1)
			return (MY_ENAMETOOLONG);
		if ((acc = check_path_access(buf)) != 1)
			return (acc == 0 ? MY_ENOENT : MY_EACCESS);
	}
	ft_putendl("here");
	return (MY_EACCESS);
}

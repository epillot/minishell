/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:32:37 by epillot           #+#    #+#             */
/*   Updated: 2017/03/10 12:40:56 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*static int	get_abs_path(char *path, char abs_path[PATH_MAX])
{
	int		i;
	int		j;
	char	**sub_path;

	i = 0;
	if (*path != '/')
	{
		if (!(getcwd(abs_path, PATH_MAX)))
		{
			minishell_error(MY_ENOENT, 1, "cd", path);
			return (0);
		}
		i = ft_strlen(abs_path);
	}
	else
		abs_path[i++] = *path++;
	if (!(sub_path = ft_strsplit(path, '/')))
		minishell_error(MALLOC, 1, "cd", NULL);
	j = 0;
	while (sub_path[j])
	{
		if (!(ft_strcmp(sub_path[j], "..")))
		{
			while (abs_path[i] != '/')
				abs_path[i--] = '\0';

			j++;
		}
		else if (!(ft_strcmp(sub_path[j], ".")))
			j++;
		else
		{
			if (abs_path[i - 1] != '/')
				abs_path[i++] = '/';
			if (ft_strlen(sub_path[j]) + ft_strlen(abs_path) >= PATH_MAX)
			{
				minishell_error(MY_ENAMETOOLONG, 1, "cd", path);
				return (0);
			}
			ft_strcat(abs_path, sub_path[j]);
			i += ft_strlen(sub_path[j]);
			j++;
		}
		if (!(check_error_path(abs_path, 1, "cd")))
			return (0);
	}
	return (1);
}

int main(int ac , char **av)
{
	char path[PATH_MAX];

	if (ac != 2)
		return (1);
	get_abs_path(av[1], path);
	ft_putendl(path);
}*/

static void	exec_cd(char *path)
{
	char	full_path[PATH_MAX];

	ft_bzero(full_path, PATH_MAX);
	if (*path != '/')
		get_full_path(path, full_path);

}

void		ft_cd(char *path, char ***env)
{
	struct stat	buf;
	char		abs_path[PATH_MAX];

	ft_bzero(abs_path, PATH_MAX);
	if (!(get_absolute_path(path, abs_path)))
		return ;
	if (lstat(path, &buf) != -1)
	{
		if (!S_ISDIR(buf.st_mode))
			minishell_error(MY_ENOTDIR, 1, "cd", path);
		else
		{
			if (access(path, X_OK) == 0)
				exec_cd(path, env);
			else
				minishell_error(MY_EACCESS, 1, "cd", path);
		}
	}
	else
		check_error_path(path, 1, "cd");
}

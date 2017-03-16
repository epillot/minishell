/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:32:37 by epillot           #+#    #+#             */
/*   Updated: 2017/03/16 18:31:25 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_env_val(char *val, char **env)
{
	char	**tg;

	tg = ft_getenv(val, env);
	if (tg && *(*tg + ft_strlen(val) + 1) != '\0')
		return (*tg + ft_strlen(val) + 1);
	minishell_error(ENVNOTSET, 1, "cd", val);
	return (NULL);
}

static char	*get_cd_path(char *path, char **env, int *put)
{
	char	*new_path;
	char	*val;

	if (!path)
	{
		if (!(val = get_env_val("HOME", env)))
			return (NULL);
		if (!(new_path = ft_strdup(val)))
			minishell_error(MALLOC, 0, NULL, NULL);
	}
	else if (ft_strcmp(path, "-") == 0)
	{
		if (!(val = get_env_val("OLDPWD", env)))
			return (NULL);
	//	ft_putendl(val);
		*put = 1;
		if (!(new_path = ft_strdup(val)))
			minishell_error(MALLOC, 0, NULL, NULL);
	}
	else if (*path == '~')
	{
		if (!(val = get_env_val("HOME", env)))
			return (NULL);
		if (!(new_path = ft_strjoin(val, path + 1)))
			minishell_error(MALLOC, 0, NULL, NULL);
	}
	else
	{
		if (!(new_path = ft_strdup(path)))
			minishell_error(MALLOC, 0, NULL, NULL);
	}
	return (new_path);
}

static void	check_error_cd(char *cd_path, char *cwd)
{
	struct stat buf;

	free(cwd);
	if (stat(cd_path, &buf) != -1)
	{
		 if (!S_ISDIR(buf.st_mode))
			 minishell_error(MY_ENOTDIR, 1, "cd", cd_path);
		 else if (access(cd_path, X_OK))
			 minishell_error(MY_EACCESS, 1, "cd", cd_path);
	}
	else
		minishell_error(check_error_path(cd_path), 1, "cd", cd_path);
	free(cd_path);
}

void		ft_cd(char *path, char ***env)
{
	char		*cwd;
	char		*cd_path;
	int			put;

	put = 0;
	if (!(cd_path = get_cd_path(path, *env, &put)))
		return ;
	if (!(cwd = getcwd(NULL, 0)))
	{
		ft_putstr_fd("minishell: cd: error retrieving current directory: ", 2);
		ft_putendl_fd("getcwd: cannot access parent directories.", 2);
		if (!(cwd = ft_strdup("")))
			minishell_error(MALLOC, 0, NULL, NULL);
	}
	if (chdir(cd_path) == 0)
	{
		if (put)
			ft_putendl(cd_path);
		manage_env("OLDPWD", cwd, env);
		free(cwd);
		if (!(cwd = getcwd(NULL, 0)))
			minishell_error(MALLOC, 0, NULL, NULL);
		manage_env("PWD", cwd, env);
		free(cwd);
		free(cd_path);
	}
	else
		check_error_cd(cd_path, cwd);
}

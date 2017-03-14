/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:32:37 by epillot           #+#    #+#             */
/*   Updated: 2017/03/14 15:42:17 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_env_val(char *var, char **env)
{
	char	*output;
	
	while (*env && ft_strncmp(*env, var, ft_strlen(var)) != 0)
		env++;
	if (!*env)
	{
		minishell_error(ENVNOTSET, 1, "cd", var);
		return (NULL);
	}
	if (!(output = ft_strdup(*env + ft_strlen(var))))
		minishell_error(MALLOC, 0, NULL, NULL);
	return (output);
}

static char	*get_cd_path(char *path, char **env)
{
	char	*new_path;
	char	*home;

	if (!path)
		return (get_env_val("HOME=", env));
	else if (ft_strcmp(path, "-") == 0)
	{
		new_path = get_env_val("OLDPWD=", env);
		if (new_path)
			ft_putendl(new_path);
	}
	else if (*path == '~')
	{
		if (!(home = get_env_val("HOME=", env)))
			return (NULL);
		if (!(new_path = ft_strjoin(home, path + 1)))
			minishell_error(MALLOC, 0, NULL, NULL);
	}
	else
	{
		if (!(new_path = ft_strdup(path)))
			minishell_error(MALLOC, 0, NULL, NULL);
	}
	return (new_path);
}

void		ft_cd(char *path, char ***env)
{
	struct stat	buf;
	char		*cwd;
	char		*cd_path;

	if (!(cwd = getcwd(NULL, 0)))
		return ;
	if (!(cd_path = get_cd_path(path, *env)))
		return ;
	if (chdir(cd_path) == 0)
	{
		ft_putendl("salut comment ca va");
		manage_env("OLDPWD=", cwd, env);
		ft_putendl("bien et toi");
		free(cwd);
		cwd = getcwd(NULL, 0);
		manage_env("PWD=", cwd, env);
		free(cwd);
		free(cd_path);
	}
	else
	{
		free(cwd);
		if (stat(cd_path, &buf) != -1)
		{
			if (!S_ISDIR(buf.st_mode))
				minishell_error(MY_ENOTDIR, 1, "cd", cd_path);
			else if (access(cd_path, X_OK))
				minishell_error(MY_EACCESS, 1, "cd", cd_path);
		}
		else
			check_error_path(cd_path, 1, "cd");
		free(cd_path);
	}
}

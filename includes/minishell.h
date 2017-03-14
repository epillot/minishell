/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:42:11 by epillot           #+#    #+#             */
/*   Updated: 2017/03/10 16:45:56 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "libft.h"
# include "get_next_line.h"
# include <signal.h>
# include <sys/types.h> 
# include <sys/stat.h>
# include <limits.h>
# include <fcntl.h>

enum
{
	NOT,
	CD,
	SETENV,
	UNSETENV
};

enum
{
	MY_ENOENT,
	MY_EISDIR,
	MY_EACCESS,
	MY_ENAMETOOLONG,
	MY_ENOTDIR,
	CMDNOTFOUND,
	ENVNOTSET,
	MALLOC
};

char **minishell_init(char **envi);
int		get_cmd_path(char **bin_path, char *cmd, char **cmd_path);
void	process_cmd(char **bin_path, char *line, char ***env);
int		check_error_path(char *path, int builtin, char *builtname);
void	minishell_error(int errnum, int builtin, char *builtname, char *str);
void	manage_env(char *var, char *newval, char ***env);
char    **ft_getenv(char *name, char **env);
void	ft_cd(char *path, char ***env);
void    ft_setenv(char **arg, char ***env);
void    ft_unsetenv(char **arg, char **env);

#endif

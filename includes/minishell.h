/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:42:11 by epillot           #+#    #+#             */
/*   Updated: 2017/03/17 17:42:22 by epillot          ###   ########.fr       */
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
# include <term.h>
# include <termios.h>
# include <dirent.h>

enum
{
	NOT,
	CD,
	SETENV,
	UNSETENV,
	MYECHO,
	ENV,
	EXIT,
	PWD
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

char	**minishell_init(char **envi);
char	**parse_line(char const *s);
int		get_cmd_path(char *cmd, char **env, char **cmd_path);
void	process_cmd(char **cmd, char ***env);
int		check_error_path(char *path);
void	minishell_error(int errnum, char *builtin, char *str);
void	manage_env(char *var, char *newval, char ***env);
char	**ft_getenv(char *name, char **env);
char	*get_env_val(char *val, char **env);
void	ft_cd(char *path, char ***env);
void	ft_setenv(char **arg, char ***env);
void	ft_unsetenv(char **arg, char **env);
void	ft_echo(char **param, char **env);
void	ft_env(char **cmd, char **env);
void	exec_cmd_env(char **cmd, char ***env);
int     ft_getcwd(char **pwd);
void ft_pwd(void);

#endif

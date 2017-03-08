/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:42:11 by epillot           #+#    #+#             */
/*   Updated: 2017/03/08 18:37:29 by epillot          ###   ########.fr       */
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

enum
{
	MY_ENOENT,
	MY_EISDIR,
	MY_EACCESS,
	MY_ENAMETOOLONG,
	MY_ENOTDIR,
	MALLOC
};

int		check_access(char *path, char *cmd);
void	process_cmd(char **bin_path, char *line, char **env);
void	check_error_path(char *path, int builtin, char *builtname);
void	minishell_error(int errnum, int builtin, char *builtname, char *str);

#endif

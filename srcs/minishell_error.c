/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:19:20 by epillot           #+#    #+#             */
/*   Updated: 2017/03/15 16:57:30 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(int errnum)
{
	if (errnum == MY_ENOENT)
		ft_putendl_fd("No such file or directory", 2);
	else if (errnum == CMDNOTFOUND)
		ft_putendl_fd("command not found", 2);
	else if (errnum == MY_EISDIR)
		ft_putendl_fd("is a directory", 2);
	else if (errnum == MY_EACCESS)
		ft_putendl_fd("Permission denied", 2);
	else if (errnum == MY_ENAMETOOLONG)
		ft_putendl_fd("File name too long", 2);
	else if (errnum == MY_ENOTDIR)
		ft_putendl_fd("Not a directory", 2);
	else if (errnum == ENVNOTSET)
		ft_putendl_fd("not set", 2);
	else
	{
		ft_putendl_fd("Malloc error", 2);
		exit(EXIT_FAILURE);
	}
}

void		minishell_error(int errnum, int builtin, char *builtname, char *str)
{
	ft_putstr_fd("minishell: ", 2);
	if (builtin)
	{
		ft_putstr_fd(builtname, 2);
		ft_putstr_fd(": ", 2);
	}
	if (errnum != MALLOC)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
	}
	print_error(errnum);
}

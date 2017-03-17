/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:09:24 by epillot           #+#    #+#             */
/*   Updated: 2017/03/17 14:54:50 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_one(char *param, char **env)
{
	char	**tg;
	int		i;

	i = 0;
	while (*param)
	{
		if (*param == '$' && *(param + 1) != '\0' && *(param + 1) != ' ')
		{
			param++;
			tg = ft_getenv(param, env);
			if (tg)
			{
				while ((*tg)[i] && (*tg)[i] != '=')
					i++;
				ft_putstr(*tg + i + 1);
			}
			return ;
		}
		else
			ft_putchar(*param);
		param++;
	}
}

void		ft_echo(char **param, char **env)
{
	int		optn;

	optn = 0;
	if (ft_strcmp(*param, "-n") == 0)
	{
		optn = 1;
		param++;
	}
	while (*param)
	{
		print_one(*param, env);
		param++;
		if (*param)
			ft_putchar(' ');
	}
	if (optn == 0)
		ft_putchar('\n');
}

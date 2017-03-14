/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 12:25:28 by epillot           #+#    #+#             */
/*   Updated: 2017/03/14 16:01:19 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env_remove(char **env)
{
	int		i;

	i = 0;
	if (*env)
	{
		free(*env);
		*env = *(env + 1);
		while (env[i])
		{
			env[i] = env[i + 1];
			i++;
		}
	}
}

void		ft_unsetenv(char **arg, char **env)
{
	char	**tg;

	while (*arg)
	{
		tg = ft_getenv(*arg, env);
		if (tg)
			env_remove(tg);
		arg++;
	}
}

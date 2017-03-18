/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:27:10 by epillot           #+#    #+#             */
/*   Updated: 2017/03/17 12:27:55 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_val(char *val, char **env)
{
	char	**tg;

	tg = ft_getenv(val, env);
	if (tg && *(*tg + ft_strlen(val) + 1) != '\0')
		return (*tg + ft_strlen(val) + 1);
	minishell_error(ENVNOTSET, "cd", val);
	return (NULL);
}

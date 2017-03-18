/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 12:27:24 by epillot           #+#    #+#             */
/*   Updated: 2017/03/14 16:30:45 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_getenv(char *name, char **env)
{
	size_t	len;
	char	*tmp;

	if (!(tmp = ft_strjoin(name, "=")))
		minishell_error(MALLOC, NULL, NULL);
	len = ft_strlen(tmp);
	while (*env)
	{
		if (ft_strncmp(*env, tmp, len) == 0)
		{
			free(tmp);
			return (env);
		}
		env++;
	}
	free(tmp);
	return (NULL);
}

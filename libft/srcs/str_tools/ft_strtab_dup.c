/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:37:04 by epillot           #+#    #+#             */
/*   Updated: 2017/03/17 13:37:19 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtab_dup(char **str)
{
	char	**out;
	int		i;

	i = 0;
	while (str[i])
		i++;
	out = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	if (out)
	{
		i = 0;
		while (str[i])
		{
			if (!(out[i] = ft_strdup(str[i])))
			{
				ft_strtab_free(out);
				return (NULL);
			}
			i++;
		}
	}
	return (out);
}

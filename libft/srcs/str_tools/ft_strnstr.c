/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:55:07 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:10:41 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i])
	{
		while (big[i + j] == little[j] && i + j < n)
		{
			j++;
			if (little[j] == '\0')
				return ((char*)(big + i));
		}
		j = 0;
		i++;
	}
	return (NULL);
}

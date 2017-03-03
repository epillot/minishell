/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:46:27 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:11:47 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i])
	{
		while (big[i + j] == little[j])
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

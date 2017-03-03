/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:59:50 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:05:31 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char octet;

	octet = c;
	if (octet == '\0')
		return ((char*)(s + ft_strlen(s)));
	while (*s)
	{
		if (*s == octet)
			return ((char*)s);
		s++;
	}
	return (NULL);
}

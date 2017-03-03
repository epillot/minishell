/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:29:54 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:11:07 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	octet;
	int		s_len;

	octet = c;
	s_len = ft_strlen(s);
	while (s_len >= 0)
	{
		if (s[s_len] == octet)
			return ((char*)(s + s_len));
		s_len--;
	}
	return (NULL);
}

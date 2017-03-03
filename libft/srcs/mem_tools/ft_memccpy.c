/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:29:17 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:16:52 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t					i;

	i = 0;
	while (i < n)
	{
		*(t_byte*)(dst + i) = *(t_byte*)(src + i);
		if (*(t_byte*)(dst + i) == (t_byte)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:37:02 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:18:12 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (src > dst || n == 0)
		return (ft_memcpy(dst, src, n));
	while (n--)
		*(t_byte*)(dst + n) = *(t_byte*)(src + n);
	return (dst);
}

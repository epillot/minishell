/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:04:12 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:20:24 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_itoa_size(intmax_t n, int base)
{
	int size;

	size = 1;
	if (n < 0 && base == 10)
		size++;
	while (n >= base || n <= -base)
	{
		size++;
		n /= base;
	}
	return (size);
}

char		*ft_itoa_base(intmax_t n, int base)
{
	int		i;
	int		size;
	char	*output;
	char	itoa_base[16];

	if (base < 2 || base > 16)
		return (NULL);
	i = 0;
	ft_strncpy(itoa_base, "0123456789ABCDEF", base);
	size = get_itoa_size(n, base);
	if (!(output = ft_strnew(size)))
		return (NULL);
	if (n < 0 && base == 10)
		output[i++] = '-';
	while (size - 1 >= i)
	{
		output[size - 1] = itoa_base[ft_abs(n % base)];
		size--;
		n /= base;
	}
	return (output);
}

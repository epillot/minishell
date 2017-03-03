/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:39:54 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:12:55 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned char octet)
{
	int max;

	max = 128;
	while (max)
	{
		if (octet >= max)
		{
			ft_putchar('1');
			octet -= max;
		}
		else
			ft_putchar('0');
		max /= 2;
	}
}

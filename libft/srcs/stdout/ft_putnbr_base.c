/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:07:24 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:14:23 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_base_aux(int n, char *base)
{
	int		base_len;

	base_len = (int)ft_strlen(base);
	if (n >= base_len || n <= -base_len)
		ft_putnbr_base_aux(n / base_len, base);
	ft_putchar(base[ft_abs(n % base_len)]);
}

void			ft_putnbr_base(int n, char *base)
{
	if (n < 0)
		ft_putchar('-');
	ft_putnbr_base_aux(n, base);
}

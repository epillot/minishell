/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:24:20 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:14:34 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_aux_fd(int n, int fd)
{
	if (n > 9 || n < -9)
		ft_putnbr_aux_fd(n / 10, fd);
	ft_putchar_fd('0' + ft_abs(n % 10), fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_putnbr_aux_fd(n, fd);
}

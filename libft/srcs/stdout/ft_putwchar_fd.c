/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:05:28 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:15:37 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putwchar_11b_fd(wint_t c, int fd)
{
	wint_t	d;
	wint_t	e;
	wint_t	filtre;

	d = 0xc0;
	e = 0x80;
	filtre = 0x3f;
	e = e | (filtre & c);
	d = d | (c >> 6);
	ft_putchar_fd((char)d, fd);
	ft_putchar_fd((char)e, fd);
}

static void	ft_putwchar_16b_fd(wint_t c, int fd)
{
	wint_t	d;
	wint_t	e;
	wint_t	f;
	wint_t	filtre;

	f = 0x80;
	e = 0x80;
	d = 0xe0;
	filtre = 0x3f;
	f = f | (filtre & c);
	e = e | (filtre & (c >> 6));
	filtre = 0xf;
	d = d | (filtre & (c >> 12));
	ft_putchar_fd((char)d, fd);
	ft_putchar_fd((char)e, fd);
	ft_putchar_fd((char)f, fd);
}

static void	ft_putwchar_21b_fd(wint_t c, int fd)
{
	wint_t	d;
	wint_t	e;
	wint_t	f;
	wint_t	g;
	wint_t	filtre;

	g = 0x80;
	f = 0x80;
	e = 0x80;
	d = 0xf0;
	filtre = 0x3f;
	g = g | (filtre & c);
	f = f | (filtre & (c >> 6));
	e = f | (filtre & (c >> 12));
	filtre = 0x7;
	d = d | (filtre & (c >> 18));
	ft_putchar_fd((char)d, fd);
	ft_putchar_fd((char)e, fd);
	ft_putchar_fd((char)f, fd);
	ft_putchar_fd((char)g, fd);
}

void		ft_putwchar_fd(wint_t c, int fd)
{
	if (c <= 0x7f)
		ft_putchar_fd((char)c, fd);
	if (c >= 0x80 && c <= 0x7ff)
		ft_putwchar_11b_fd(c, fd);
	if (c >= 0x800 && c <= 0xffff)
		ft_putwchar_16b_fd(c, fd);
	if (c >= 0x10000 && c <= 0x10ffff)
		ft_putwchar_21b_fd(c, fd);
}

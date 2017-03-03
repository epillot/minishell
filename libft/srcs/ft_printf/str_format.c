/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:21:24 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:25:17 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_option(t_option *st)
{
	ft_bzero(st, sizeof(t_option));
	st->flag.width = ' ';
	st->precision = -1;
}

static void	adjust_option(t_option *st)
{
	if (is_signed_conv(*st) || is_unsigned_conv(*st))
		if (st->precision != -1)
			st->flag.width = ' ';
	if (st->flag.left_adjust == 1)
		st->flag.width = ' ';
	if (st->flag.space == 1 && st->flag.sign == 0)
		st->flag.sign = ' ';
	else if (st->flag.sign == 1)
		st->flag.sign = '+';
	if (st->id == 'p')
		st->flag.conv = 1;
}

char		*str_format(const char **s, t_option *st, va_list ap, int *size)
{
	char	*str;

	init_option(st);
	get_option(s, st, ap);
	adjust_option(st);
	if (is_signed_conv(*st))
		d_convert(&str, *st, ap, size);
	else if (is_unsigned_conv(*st))
		u_convert(&str, *st, ap, size);
	else if (st->id == 'C' || (st->id == 'c' && st->length.l >= 1))
		wc_convert(&str, *st, ap, size);
	else if (st->id == 'S' || (st->id == 's' && st->length.l >= 1))
		ws_convert(&str, *st, ap, size);
	else if (st->id == 's' && st->length.l == 0)
		s_convert(&str, *st, ap, size);
	else if (st->id == 'n')
	{
		if (!(str = ft_strdup("")))
			return (NULL);
		*size = -1;
	}
	else
		c_convert(&str, *st, ap, size);
	return (str);
}

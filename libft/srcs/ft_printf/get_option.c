/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:27:32 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:24:43 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_flag_info(const char c, t_option *st)
{
	if (c == '#')
		st->flag.conv = 1;
	else if (c == '0')
		st->flag.width = '0';
	else if (c == '-')
		st->flag.left_adjust = 1;
	else if (c == ' ')
		st->flag.space = 1;
	else if (c == '+')
		st->flag.sign = 1;
}

static void	get_length_info(const char c, t_option *st)
{
	if (c == 'h')
		st->length.h++;
	else if (c == 'l')
		st->length.l++;
	else if (c == 'j')
		st->length.j = 1;
	else if (c == 'z')
		st->length.z = 1;
}

static void	get_field_width(const char **format, t_option *st, va_list ap)
{
	if (ft_isdigit(**format))
	{
		st->field_width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
		(*format)--;
	}
	else
	{
		st->field_width = va_arg(ap, int);
		if (st->field_width < 0)
		{
			st->field_width *= -1;
			st->flag.left_adjust = 1;
		}
	}
}

static void	get_precision(const char **format, t_option *st, va_list ap)
{
	(*format)++;
	if (ft_isdigit(**format))
	{
		st->precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
		(*format)--;
	}
	else if (**format == '*')
	{
		st->precision = va_arg(ap, int);
		if (st->precision < 0)
			st->precision = -1;
	}
	else
	{
		st->precision = 0;
		(*format)--;
	}
}

void		get_option(const char **format, t_option *st, va_list ap)
{
	while (is_format_info(**format))
	{
		if (is_flag(**format))
			get_flag_info(**format, st);
		else if (is_length_info(**format))
			get_length_info(**format, st);
		else if (ft_isdigit(**format) || **format == '*')
			get_field_width(format, st, ap);
		else if (**format == '.')
			get_precision(format, st, ap);
		(*format)++;
	}
	st->id = **format;
	if (st->id)
		(*format)++;
}

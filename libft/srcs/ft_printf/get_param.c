/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:03:38 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:24:53 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_param_for_signed_conv(va_list ap, t_option st)
{
	intmax_t	output;

	if (st.length.l >= 2)
		output = (intmax_t)va_arg(ap, long long);
	else if (st.length.l == 1 || st.id == 'D')
		output = (intmax_t)va_arg(ap, long);
	else if (st.length.z >= 1)
		output = (intmax_t)va_arg(ap, ssize_t);
	else if (st.length.j >= 1)
		output = va_arg(ap, intmax_t);
	else if (st.length.h >= 2)
		output = (intmax_t)(char)va_arg(ap, int);
	else if (st.length.h == 1)
		output = (intmax_t)(short)va_arg(ap, int);
	else
		output = (intmax_t)va_arg(ap, int);
	return (output);
}

uintmax_t	get_param_for_unsigned_conv(va_list ap, t_option st)
{
	uintmax_t	output;

	if (st.length.l >= 2)
		output = (uintmax_t)va_arg(ap, unsigned long long);
	else if (st.length.l == 1 || st.id == 'O' || st.id == 'U')
		output = (uintmax_t)va_arg(ap, unsigned long);
	else if (st.length.z >= 1 || st.id == 'p')
		output = (uintmax_t)va_arg(ap, size_t);
	else if (st.length.j >= 1)
		output = va_arg(ap, uintmax_t);
	else if (st.length.h >= 2)
		output = (uintmax_t)(unsigned char)va_arg(ap, unsigned int);
	else if (st.length.h == 1)
		output = (uintmax_t)(unsigned short)va_arg(ap, unsigned int);
	else
		output = (uintmax_t)va_arg(ap, unsigned int);
	return (output);
}

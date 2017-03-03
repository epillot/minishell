/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_for_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:03:33 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:25:28 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_octal_conv(t_option st)
{
	return (st.id == 'o' || st.id == 'O');
}

int		is_hexa_conv(t_option st)
{
	return (st.id == 'x' || st.id == 'X' || st.id == 'p');
}

int		get_base(t_option st)
{
	if (st.id == 'u' || st.id == 'U')
		return (10);
	if (is_octal_conv(st))
		return (8);
	if (is_hexa_conv(st))
		return (16);
	return (2);
}

int		is_signed_conv(t_option st)
{
	if (st.id == 'd' || st.id == 'i' || st.id == 'D')
		return (1);
	return (0);
}

int		is_unsigned_conv(t_option st)
{
	if (is_octal_conv(st) || is_hexa_conv(st) || st.id == 'u'
			|| st.id == 'U' || st.id == 'b')
		return (1);
	return (0);
}

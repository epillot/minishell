/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:35:33 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:25:53 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_wchar_size(wint_t c)
{
	if (c >= 0 && c <= 0x7f)
		return (1);
	if (c >= 0x80 && c <= 0x7ff)
		return (2);
	if ((c >= 0x800 && c <= 0xd7ff) || (c >= 0xe000 && c <= 0xffff))
		return (3);
	if (c >= 0x10000 && c <= 0x10ffff)
		return (4);
	return (0);
}

static int	get_total_size(int size_c, t_option st)
{
	int size;

	size = size_c;
	if (size < st.field_width)
		size = st.field_width;
	return (size);
}

static char	*wc_to_formated_string(wint_t c, t_option st, int *n)
{
	char	*output;
	int		size;
	int		size_c;
	int		i;

	if (!(size_c = get_wchar_size(c)))
		return (NULL);
	size = get_total_size(size_c, st);
	*n = size;
	if (!(output = ft_strnew(size)))
		return (NULL);
	i = (st.flag.left_adjust == 1 ? size_c : 0);
	while (size-- > size_c)
		output[i++] = st.flag.width;
	if (st.flag.left_adjust == 1)
		i = 0;
	encode_unicode(c, &i, output);
	return (output);
}

void		wc_convert(char **str, t_option st, va_list ap, int *size)
{
	wint_t	c;

	c = va_arg(ap, wint_t);
	*str = wc_to_formated_string(c, st, size);
}

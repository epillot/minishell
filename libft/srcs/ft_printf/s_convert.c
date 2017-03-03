/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:28:51 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:25:08 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_s_size(char *s, t_option *st)
{
	int	size;

	size = ft_strlen(s);
	if (st->precision == -1)
		st->precision = 2147483647;
	if (st->precision < size)
		return (st->precision);
	return (size);
}

char		*s_to_formated_string(char *s, t_option st, int *n)
{
	char	*output;
	int		size;
	int		size_s;
	int		i;

	if (s == NULL)
		s = "(null)";
	size_s = get_s_size(s, &st);
	size = size_s;
	if (size_s < st.field_width)
		size = st.field_width;
	*n = size;
	if (!(output = ft_strnew(size)))
		return (NULL);
	i = (st.flag.left_adjust == 1 ? size_s : 0);
	while (size-- > size_s)
		output[i++] = st.flag.width;
	if (st.flag.left_adjust == 1)
		i = 0;
	while (size_s-- > 0)
		output[i++] = *s++;
	return (output);
}

void		s_convert(char **str, t_option st, va_list ap, int *size)
{
	char	*s;

	s = va_arg(ap, char*);
	*str = s_to_formated_string(s, st, size);
}

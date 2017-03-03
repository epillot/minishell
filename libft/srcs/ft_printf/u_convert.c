/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:35:09 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:25:44 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_number_size(uintmax_t n, int base, t_option *st)
{
	int size;

	size = 1;
	if (n == 0 && st->precision == 0)
	{
		if (is_octal_conv(*st) && st->flag.conv == 1)
			return (1);
		return (0);
	}
	while (n >= (uintmax_t)base)
	{
		size++;
		n /= base;
	}
	if (is_octal_conv(*st) && st->flag.conv == 1 && st->precision <= size && n)
		return (size + 1);
	if (size < st->precision)
		return (st->precision);
	return (size);
}

static int	get_total_size(uintmax_t n, int size_n, t_option st)
{
	int size;

	size = size_n;
	if (st.id == 'p' || (is_hexa_conv(st) && st.flag.conv == 1 && n != 0))
		size += 2;
	if (st.field_width > size)
		size = st.field_width;
	return (size);
}

static int	apply_option(uintmax_t n, char *s, t_option st, t_size size)
{
	int		i;
	int		j;

	j = 0;
	if (st.id == 'p' || (is_hexa_conv(st) && st.flag.conv == 1 && n != 0))
		j = 2;
	if (st.flag.left_adjust != 0 || st.flag.width == '0')
		i = 0;
	else if (!j)
		i = size.tot - size.n - 1;
	else
		i = size.tot - size.n - 2;
	if (j == 2)
	{
		s[i++] = '0';
		s[i++] = 'x';
	}
	if (st.flag.width != '0')
		i = (st.flag.left_adjust != 0 ? i + size.n : 0);
	while (size.tot-- > size.n + j)
		s[i++] = st.flag.width;
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*u_to_formated_string(uintmax_t n, int base, t_option st, int *nb)
{
	int		i;
	t_size	size;
	char	*output;
	char	dig[16];

	ft_strncpy(dig, "0123456789abcdef", base);
	size.n = get_number_size(n, base, &st);
	size.tot = get_total_size(n, size.n, st);
	*nb = size.tot;
	if (!(output = ft_strnew(size.tot)))
		return (NULL);
	i = apply_option(n, output, st, size);
	while (size.n > 0)
	{
		output[size.n - 1 + i] = dig[ft_abs(n % base)];
		size.n--;
		n /= base;
	}
	return (st.id == 'X' ? ft_strupcase(output) : output);
}

void		u_convert(char **str, t_option st, va_list ap, int *size)
{
	uintmax_t	n;
	int			base;

	n = get_param_for_unsigned_conv(ap, st);
	base = get_base(st);
	*str = u_to_formated_string(n, base, st, size);
}

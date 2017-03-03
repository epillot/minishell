/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:03:19 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:24:12 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_formated_s(const char **format, va_list ap, char **s, int ret)
{
	t_option	st;
	char		*tmp1;
	char		*tmp2;
	int			size;
	int			n_option;

	n_option = 0;
	(*format)++;
	tmp1 = *s;
	if (!(*s = str_format(format, &st, ap, &size)))
		return (-1);
	if (size == -1)
	{
		size = 0;
		n_option = 1;
	}
	tmp2 = *s;
	if (!(*s = ft_strnjoin(tmp1, tmp2, ret, size)))
		return (-1);
	free(tmp1);
	free(tmp2);
	if (n_option)
		return (-2);
	return (size);
}

static void	apply_n_option(int ret, int *size, va_list ap)
{
	int	*n;

	n = va_arg(ap, int*);
	if (n != NULL)
		*n = ret;
	*size = 0;
}

static int	add_other_part(const char *format, int ret, char **s)
{
	char	*tmp;
	int		i;

	tmp = *s;
	i = 0;
	while (*(format + i) && *(format + i) != '%')
		i++;
	if (!(*s = ft_strnjoin(*s, format, ret, i)))
		return (-1);
	free(tmp);
	return (i);
}

static int	ft_printf_aux(const char *format, va_list ap, char **s)
{
	int			size;
	int			ret;

	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if ((size = add_formated_s(&format, ap, s, ret)) == -1)
				return (-1);
			if (size == -2)
				apply_n_option(ret, &size, ap);
			ret += size;
		}
		else
		{
			if ((size = add_other_part(format, ret, s)) == -1)
				return (-1);
			format += size;
			ret += size;
		}
	}
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;
	char		*s;

	if (!(s = ft_strdup("")))
		return (-1);
	va_start(ap, format);
	ret = ft_printf_aux(format, ap, &s);
	write(1, s, ret);
	free(s);
	va_end(ap);
	return (ret);
}

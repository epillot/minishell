/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:38:49 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:23:36 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*c_to_formated_string(unsigned char c, t_option st, int *n)
{
	char	*output;
	int		size;
	int		i;

	size = 1;
	if (st.field_width > 1)
		size = st.field_width;
	*n = size;
	if (!(output = ft_strnew(size)))
		return (NULL);
	i = (st.flag.left_adjust == 1 ? 1 : 0);
	while (size-- > 1)
		output[i++] = st.flag.width;
	if (st.flag.left_adjust == 1)
		i = 0;
	output[i] = (char)c;
	return (output);
}

void		c_convert(char **str, t_option st, va_list ap, int *size)
{
	unsigned char c;

	if (st.id == 'c')
		c = (unsigned char)va_arg(ap, int);
	else if (st.id)
		c = st.id;
	else
	{
		*size = 0;
		*str = ft_strdup("");
		return ;
	}
	*str = c_to_formated_string(c, st, size);
}

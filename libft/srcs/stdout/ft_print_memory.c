/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:40:38 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:13:06 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_content(const t_byte *ptr, size_t size, size_t start)
{
	size_t	i;

	i = 0;
	while (start + i < size && i < 16)
	{
		if (i && i % 2 == 0)
			ft_putchar(' ');
		if (ptr[start + i] < 16)
			ft_putchar('0');
		ft_putnbr_base(ptr[start + i], "0123456789abcdef");
		i++;
	}
	if (start)
	{
		while (i < 16)
		{
			ft_putnchar(' ', 2);
			if (i % 2 == 0)
				ft_putchar(' ');
			i++;
		}
	}
}

static void	put_printable_char(const t_byte *ptr, size_t size, size_t start)
{
	size_t	i;

	i = 0;
	while (start + i < size && i < 16)
	{
		if (ft_isprint(ptr[start + i]))
			ft_putchar(ptr[start + i]);
		else
			ft_putchar('.');
		i++;
	}
}

void		*ft_print_memory(const void *ptr, size_t size)
{
	const t_byte	*s;
	size_t			i;

	if (!size)
		return ((void*)ptr);
	s = ptr;
	i = 0;
	while (i < size)
	{
		print_content(s, size, i);
		ft_putchar(' ');
		put_printable_char(s, size, i);
		i += 16;
		ft_putchar('\n');
	}
	return ((void*)ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_format_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:38:22 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:25:36 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_flag(const char c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
		return (1);
	return (0);
}

int	is_length_info(const char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

int	is_format_info(const char c)
{
	if (is_flag(c) || is_length_info(c)
			|| ft_isdigit(c) || c == '.' || c == '*')
		return (1);
	return (0);
}

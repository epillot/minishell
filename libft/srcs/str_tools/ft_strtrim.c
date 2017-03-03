/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:53:33 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:12:12 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char const c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static int	ft_count_endspace(char const *s)
{
	int		i;
	int		count;

	count = 0;
	i = ft_strlen(s) - 1;
	while (ft_is_space(s[i]) && i >= 0)
	{
		count++;
		i--;
	}
	return (count);
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	int		new_len;

	while (ft_is_space(*s))
		s++;
	new_len = ft_strlen(s) - ft_count_endspace(s);
	if (new_len < 0)
		new_len = 0;
	new = ft_strsub(s, 0, new_len);
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 13:35:45 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:33:51 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, int n1, int n2)
{
	int		i;
	char	*new;

	i = -1;
	if (!(new = ft_strnew(n1 + n2)))
		return (NULL);
	new = ft_memcpy(new, s1, n1);
	while (++i < n2)
		new[n1 + i] = s2[i];
	return (new);
}

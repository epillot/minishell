/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:35:34 by epillot           #+#    #+#             */
/*   Updated: 2017/03/17 13:36:33 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old, size_t new)
{
	void	*p;

	p = ft_memalloc(new);
	if (p && ptr)
	{
		if (new <= old)
			ft_memcpy(p, ptr, new);
		else
			ft_memcpy(p, ptr, old);
		free(ptr);
	}
	return (p);
}

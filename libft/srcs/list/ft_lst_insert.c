/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:31:04 by epillot           #+#    #+#             */
/*   Updated: 2017/01/31 18:32:40 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_insert(t_list **list, t_list *elem, int pos)
{
	t_list	*tmp;

	if (pos == 1)
		ft_lstadd(list, elem);
	else
	{
		tmp = ft_lst_at(*list, pos - 1);
		if (tmp)
		{
			elem->next = tmp->next;
			tmp->next = elem;
		}
	}
}

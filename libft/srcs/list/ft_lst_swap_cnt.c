/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_swap_cnt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:38:28 by epillot           #+#    #+#             */
/*   Updated: 2017/01/27 14:39:27 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_swap_cnt(t_list *elem1, t_list *elem2)
{
	void	*tmp;

	tmp = elem1->content;
	elem1->content = elem2->content;
	elem2->content = tmp;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:59:27 by epillot           #+#    #+#             */
/*   Updated: 2017/01/31 17:48:58 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *alst;
	tmp2 = tmp1->next;
	while (tmp2)
	{
		ft_lstdelone(&tmp1, del);
		tmp1 = tmp2;
		tmp2 = tmp1->next;
	}
	ft_lstdelone(&tmp1, del);
	*alst = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:38:55 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:19:36 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
	t_list *tmp1;
	t_list *tmp2;
	t_list *tmp3;

	if (lst == NULL)
		return (NULL);
	tmp1 = lst;
	tmp2 = (*f)(tmp1);
	if ((new_lst = ft_lstnew(tmp2->content, tmp2->content_size)) == NULL)
		return (NULL);
	tmp3 = new_lst;
	lst = lst->next;
	while (lst)
	{
		tmp1 = lst;
		tmp2 = (*f)(tmp1);
		tmp1 = ft_lstnew(tmp2->content, tmp2->content_size);
		if (tmp1 == NULL)
			return (NULL);
		tmp3->next = tmp1;
		tmp3 = tmp1;
		lst = lst->next;
	}
	return (new_lst);
}

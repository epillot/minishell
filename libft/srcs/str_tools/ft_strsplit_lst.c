/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:21:38 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:11:36 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_strsplit_lst(char const *s, char c)
{
	t_list	*lst_str;
	t_list	*elem;
	char	**tab_str;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	tab_str = ft_strsplit(s, c);
	while (tab_str[i])
		i++;
	i--;
	lst_str = ft_lstnew(tab_str[i], ft_strlen(tab_str[i]) + 1);
	i--;
	while (i >= 0)
	{
		elem = ft_lstnew(tab_str[i], ft_strlen(tab_str[i]) + 1);
		ft_lstadd(&lst_str, elem);
		i--;
	}
	i = 0;
	while (tab_str[i])
		free(tab_str[i++]);
	free(tab_str);
	return (lst_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:04:22 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:11:26 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_word(char a, char b, char space)
{
	if (a != space && (b == space || b == '\0'))
		return (1);
	return (0);
}

static int	ft_count_word(char const *s, char space)
{
	int count;

	count = 0;
	while (*s)
	{
		if (ft_is_word(*s, *(s + 1), space))
			count++;
		s++;
	}
	return (count);
}

static int	ft_word_len(char const *word, char space)
{
	int i;

	i = 1;
	while (!ft_is_word(word[0], word[i], space))
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab_str;
	int		nb_word;
	int		i;
	int		word_len;

	i = 0;
	nb_word = ft_count_word(s, c);
	if (!(tab_str = (char **)ft_memalloc(sizeof(char *) * (nb_word + 1))))
		return (NULL);
	while (i < nb_word)
	{
		while (*s == c)
		{
			s++;
			if (*s == '\0')
				return (tab_str);
		}
		word_len = ft_word_len(s, c);
		tab_str[i] = ft_strsub(s, 0, word_len);
		s += word_len;
		i++;
	}
	return (tab_str);
}

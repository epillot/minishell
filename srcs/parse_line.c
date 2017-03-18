/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 12:37:54 by epillot           #+#    #+#             */
/*   Updated: 2017/03/14 12:47:53 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_shell_space(char c)
{
	return (c == ' ' || c == '\t');
}

static int	ft_is_word(char a, char b)
{
	if (!is_shell_space(a) && (is_shell_space(b) || b == '\0'))
		return (1);
	return (0);
}

static int	ft_count_word(char const *s)
{
	int count;

	count = 0;
	while (*s)
	{
		if (ft_is_word(*s, *(s + 1)))
			count++;
		s++;
	}
	return (count);
}

static int	ft_word_len(char const *word)
{
	int i;

	i = 1;
	while (!ft_is_word(word[0], word[i]))
		i++;
	return (i);
}

char		**parse_line(char const *s)
{
	char	**tab_str;
	int		nb_word;
	int		i;
	int		word_len;

	i = 0;
	nb_word = ft_count_word(s);
	if (!(tab_str = (char **)ft_memalloc(sizeof(char *) * (nb_word + 1))))
		minishell_error(MALLOC, NULL, NULL);
	while (i < nb_word)
	{
		while (is_shell_space(*s))
		{
			s++;
			if (*s == '\0')
				return (tab_str);
		}
		word_len = ft_word_len(s);
		tab_str[i] = ft_strsub(s, 0, word_len);
		s += word_len;
		i++;
	}
	return (tab_str);
}

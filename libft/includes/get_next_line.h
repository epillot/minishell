/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:23:35 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 18:38:33 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define BUFF_SIZE 2

typedef struct	s_buffer
{
	char			*to_add;
	char			*buf_read;
	int				size_to_add;
	int				current_size_line;
	int				fd;
	struct s_buffer *next;
	struct s_buffer *prev;
}				t_buffer;

int				get_next_line(const int fd, char **line);

#endif

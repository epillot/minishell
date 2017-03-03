/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:24:07 by epillot           #+#    #+#             */
/*   Updated: 2017/01/25 15:22:13 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include "libft.h"
#include "get_next_line.h"

static t_buffer		*create_buf(const int fd)
{
	t_buffer	*new;

	if ((new = (t_buffer*)ft_memalloc(sizeof(t_buffer))) == NULL)
		return (NULL);
	if ((new->buf_read = ft_strnew(BUFF_SIZE)) == NULL)
		return (NULL);
	new->fd = fd;
	return (new);
}

static t_buffer		*get_buffer(t_buffer *buf, const int fd)
{
	t_buffer	*new;

	if (!buf)
	{
		new = create_buf(fd);
		return (new);
	}
	while (buf->fd != fd && buf->prev)
		buf = buf->prev;
	while (buf->fd != fd && buf->next)
		buf = buf->next;
	if (buf->fd != fd)
	{
		if ((new = create_buf(fd)) == NULL)
			return (NULL);
		new->prev = buf;
		buf->next = new;
		return (new);
	}
	buf->to_add++;
	buf->current_size_line = 0;
	if (buf->size_to_add)
		buf->size_to_add--;
	return (buf);
}

static int			read_file(const int fd, t_buffer *buf)
{
	int	ret;

	ret = read(fd, buf->buf_read, BUFF_SIZE);
	if (ret)
	{
		buf->to_add = buf->buf_read;
		buf->size_to_add += ret;
	}
	return (ret);
}

static int			add_following_part(char **line, t_buffer *buf)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = *line;
	while (i < buf->size_to_add && buf->to_add[i] != '\n')
		i++;
	if ((*line = ft_strnew(buf->current_size_line + i)) == NULL)
		return (-1);
	if (tmp)
	{
		*line = ft_memmove(*line, tmp, buf->current_size_line);
		free(tmp);
	}
	i = 0;
	while (i < buf->size_to_add && buf->to_add[i] != '\n')
	{
		(*line)[buf->current_size_line + i] = buf->to_add[i];
		i++;
	}
	return (i);
}

int					get_next_line(const int fd, char **line)
{
	static t_buffer	*buf = NULL;
	int				ret;
	int				size;

	if ((fd < 0 || !line || (buf = get_buffer(buf, fd)) == NULL))
		return (-1);
	ret = 1;
	*line = NULL;
	while (buf->size_to_add || (ret = read_file(fd, buf)))
	{
		if (ret < 0)
			return (-1);
		if (buf->size_to_add)
		{
			if ((size = add_following_part(line, buf)) == -1)
				return (-1);
			buf->to_add = ft_memchr(buf->to_add, 10, buf->size_to_add);
			buf->size_to_add -= size;
			buf->current_size_line += size;
			if (buf->to_add)
				return (buf->current_size_line + 1);
		}
	}
	return (*line == NULL ? 0 : buf->current_size_line + 1);
}

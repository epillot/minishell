/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:41:02 by epillot           #+#    #+#             */
/*   Updated: 2017/03/14 15:45:11 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parse_quote(char **cmd)
{
	int		i;
	int		j;
	int		in;
	int		n;
	char	buf[PATH_MAX + 1];

	in = 0;
	n = 0;
	while (*cmd)
	{
		i = 0;
		j = 0;
		ft_bzero(buf, PATH_MAX + 1);
		while ((*cmd)[i])
		{
			if ((*cmd)[i] == '"')
			{
				n++;
				in = n % 2 == 0 ? 0 : 1;
				i++;
			}
			else if ((*cmd)[i] == '\'')
			{
				if (in)
					buf[j++] = '\'';
				i++;
			}
			else
				buf[j++] = (*cmd)[i++];
		}
		ft_strcpy(*cmd, buf);
		cmd++;
	}
}

int			main(int ac, char **av, char **envi)
{
	char	*line;
	char	**env;
	int		ret;
	char	**cmd;

	(void)ac;
	(void)av;
	env = minishell_init(envi);
	while (42)
	{
		ft_putstr("$> ");
		ret = get_next_line(0, &line);
		if (ret != 1)
			break ;
		if (line && *line)
		{
			cmd = parse_line(line);
			parse_quote(cmd);
			process_cmd(cmd, &env);
		}
		if (line)
			free(line);
	}
	if (ret == 0)
	{
		ft_putendl("exit");
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

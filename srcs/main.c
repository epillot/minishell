/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:41:02 by epillot           #+#    #+#             */
/*   Updated: 2017/03/17 17:33:41 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_quote(char **cmd)
{
	char	buf[PATH_MAX + 1];
	int		i;
	int		j;

	while (*cmd)
	{
		i = 0;
		j = 0;
		ft_bzero(buf, PATH_MAX + 1);
		while ((*cmd)[i])
		{
			if ((*cmd)[i] == '"' || (*cmd)[i] == '\'')
				i++;
			else
				buf[j++] = (*cmd)[i++];
		}
		ft_strcpy(*cmd, buf);
		cmd++;
	}
}

static void	shell_process(char *line, char ***env)
{
	char	**cmd;

	if (line && *line)
	{
		cmd = parse_line(line);
		remove_quote(cmd);
		process_cmd(cmd, env);
	}
	if (line)
		free(line);
}

int			main(int ac, char **av, char **envi)
{
	char	*line;
	char	**env;
	int		ret;

	(void)ac;
	(void)av;
	env = minishell_init(envi);
	//signal(SIGINT, ft_signal);
	while (42)
	{
		ft_printf("\033[33mMinishell \033[32m%C\033[0m ", 0x21e8);
		ret = get_next_line(0, &line);
		if (ret != 1)
			break ;
		shell_process(line, &env);
	}
	ft_strtab_free(env);
	if (ret == 0)
	{
		ft_putendl("exit");
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

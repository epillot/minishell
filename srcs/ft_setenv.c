#include "minishell.h"

static int is_valid_name(char *name)
{
	while (*name)
	{
		if (*name == '=')
			return (0);
		name++;
	}
	return (1);
}

static int setenv_error(char **arg)
{
	int i;

	i = 0;
	while (arg[i])
		i++;
	if (i < 1 || i > 2)
	{
		ft_putendl_fd("minishell: setenv: usage: setenv [name] ([value])", 2);
		return (0);
	}
	if (!is_valid_name(*arg))
	{
		ft_putendl_fd("minishell: setenv: Syntax error", 2);
		return (0);
	}
	return (1);
	
}


void	ft_setenv(char **arg, char ***env)
{
	char *value;
	char *name;

	if (!(setenv_error(arg)))
		return ;
	if (!(name = ft_strjoin(*arg, "=")))
		minishell_error(MALLOC, 0, NULL, NULL);
	value = *(arg + 1) != NULL ? *(arg + 1) : "";
	manage_env(name, value, env);
	free(name);
}

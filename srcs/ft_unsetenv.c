#include "minishell.h"

static void env_remove(char **env)
{
	int i;

	i = 0;
	if (*env)
	{
		free(*env);
		*env = *(env + 1);
		while (env[i])
		{
			env[i] = env[i + 1];
			i++;
		}
	}
}

void	ft_unsetenv(char **arg, char **env)
{
	char **tg;
	char *name;

	while (*arg)
	{
		if (!(name = ft_strjoin(*arg, "=")))
			minishell_error(MALLOC, 0, NULL, NULL);
		tg = ft_getenv(name, env);
		if (tg)
			env_remove(tg);
		free(name);
		arg++;
	}
}

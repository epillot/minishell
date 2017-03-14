#include "minishell.h"

char	**ft_getenv(char *name, char **env)
{
	size_t len;

	len = ft_strlen(name);
	while (*env)
	{
		if (ft_strncmp(*env, name, len) == 0)
			return (env);
		env++;
	}
	return (NULL);
}

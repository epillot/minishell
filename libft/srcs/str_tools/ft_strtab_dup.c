#include "libft.h"

char **ft_strtab_dup(char **str)
{
	char	**out;
	int	i;

	i = 0;
	while (str[i])
		i++;
	out = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	if (out)
	{
		i = 0;
		while (str[i])
		{
			if (!(out[i] = ft_strdup(str[i])))
			{
				ft_strtab_free(out);
				return (NULL);
			}
			i++;
		}
	}
	return (out);
}

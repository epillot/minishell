#include "includes/libft.h"

int main()
{
	char *s = ft_strdup("Ouech Ouech");
	char *o = " comment que ca va bien ?";
	size_t len = ft_strlen(s);
	size_t len2 = ft_strlen(o);
	char *s2 = ft_realloc(s, len + 1, len + len2 + 1);
	ft_strcat(s2, o);
	ft_putendl(s2);
}

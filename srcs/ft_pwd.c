#include "minishell.h"

void ft_pwd(void)
{
	char *pwd;
	int ret;

	if ((ret = ft_getcwd(&pwd)) != -1)
	{
		minishell_error(ret, "pwd", NULL);
		return ;
	}
	ft_putendl(pwd);
	free(pwd);
}

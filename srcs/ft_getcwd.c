#include "minishell.h"

static ino_t get_cur_ino(char *path)
{
	DIR *ptr;
	struct dirent *d;
	ino_t ino;

	if (!(ptr = opendir(path)))
		return (0);
	if (!(d = readdir(ptr)))
		return (0);
	ino = d->d_ino;
	closedir(ptr);
	return (ino);
}

static int get_dir_name(char *path, char name[NAME_MAX + 1])
{
	DIR *ptr;
	struct dirent *d;
	ino_t ino;
	char *prev;

	if ((ino = get_cur_ino(path)) == 0)
		return (check_error_path(path));
	if (!(prev = ft_strjoin(path, "/..")))
		minishell_error(MALLOC, NULL, NULL);
	if (!(ptr = opendir(prev)))
		return (check_error_path(prev));
	d = readdir(ptr);
	if (d->d_ino == ino)
	{
		closedir(ptr);
		free(prev);
		return (-2);
	}
	while ((d = readdir(ptr)))
	{
		if (d->d_ino == ino)
		{
			ft_strncpy(name, d->d_name, NAME_MAX + 1);
			closedir(ptr);
			free(prev);
			return (-1);
		}
	}
	return (-2);
}

int	ft_getcwd(char **pwd)
{
	char *path = ft_strdup(".");
	char name[NAME_MAX + 1];
	char *tmp;
	int ret;

	*pwd = ft_strdup("/");
	while (1)
	{
		ret = get_dir_name(path, name);
		if (ret == -2)
		{
			free(path);
			return (-1);
		}
		if (ret != -1)
		{
			free(path);
			ft_strdel(pwd);
			return (ret);
		}
		tmp = *pwd;
		if (ft_strcmp(*pwd, "/") == 0)
			ft_sprintf(pwd, "/%s", name);
		else
			ft_sprintf(pwd, "/%s%s", name, tmp);
		free(tmp);
		tmp = path;
		path = ft_strjoin(tmp, "/..");
		free(tmp);
	}
}

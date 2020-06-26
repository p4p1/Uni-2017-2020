/*
** EPITECH PROJECT, 2017
** get_path.c
** File description:
** <..>
*/

#include "minishell2.h"

void change_path(char **token, struct queue **envi)
{
	char	*path = (token[1] == NULL) ? get_home(*envi) : token[1];
	static char	tmp_path[1024];
	struct stat	st;
	int	rt = 0;

	if (my_strcmp(path, "~") == 0)
		path = get_home(*envi);
	else if (my_strcmp(path, "-") == 0)
		path = my_strdup(tmp_path);
	getcwd(tmp_path, 1024);
	rt = chdir(path);
	if (rt == -1) {
		if (path != NULL && stat(path, &st) != -1 && S_ISREG(st.st_mode))
			my_printf("%s: Not a directory.\n", path);
		else if (path != NULL && access(path, F_OK) == 0)
			my_printf("%s: Permission denied.\n", path);
		else
			my_printf((path) ? "%s: No such file or directory.\n"
					: "No $home variable set.\n", path);
	}
}

/*
** EPITECH PROJECT, 2017
** get_path.c
** File description:
** <..>
*/

#include "minishell.h"

struct queue *get_path(struct queue *env)
{
	char	*path = my_strdup("PATH");
	int	i = 0;

	while (env) {
		i = 0;
		while (i < 5) {
			if (env->token[i] == path[i])
				i++;
			else
				break;
		}
		if (my_strstr(env->token, path) && i == 4)
			return (env);
		env = env->next;
	}
	return (NULL);
}

char *extract_path(char *path, char *cmd)
{
	static int	pos = 5;
	int		i = 0;
	char		*tmp = NULL;

	if (path == NULL || cmd == NULL || path[pos] == '\0')
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * (my_strlen(path) +
				my_strlen(cmd) + 1));
	if (tmp == NULL)
		return (NULL);
	for (i = pos; path[i] != '\0' && path[i] != ':'; i++) {
		tmp[i - pos] = path[i];
	}
	tmp[i - pos] = '/';
	tmp[(i - pos) + 1] = '\0';
	pos += (i - pos) + 1;
	return (tmp);
}

void change_path(struct shell_info *si)
{
	char	*path = (si->token[1] == NULL) ? get_home(si->envi) :
		si->token[1];
	static char	tmp_path[1024];
	struct stat	st;
	int	rt = 0;

	if (my_strcmp(path, "~") == 0)
		path = get_home(si->envi);
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

int disp_env(struct shell_info *si)
{
	struct queue	*tmp = si->envi;

	while (tmp) {
		my_printf("%s\n", tmp->token);
		tmp = tmp->next;
	}
	return (0);
}

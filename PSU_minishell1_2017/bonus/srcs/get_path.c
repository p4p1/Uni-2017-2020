/*
** EPITECH PROJECT, 2017
** get_path.c
** File description:
** <..>
*/

#include "minishell.h"

struct queue *get_path(struct queue *env)
{
	char	path[5] = "PATH";

	while (env) {
		if (my_strstr(env->token, path))
			return (env);
		env = env->next;
	}
	return (NULL);
}

char *extract_path(char *path, char *cmd)
{
	static int	pos = 5;
	int		i = 0;
	char		*tmp = (char *)malloc(sizeof(char) *
				(my_strlen(path) + my_strlen(cmd)));

	if (tmp == NULL)
		return (NULL);
	for (i = pos; path[i] != '\0' && path[i] != ':'; i++) {
		tmp[i - pos] = path[i];
	}
	tmp[i - pos] = '/';
	tmp[(i - pos) + 1] = '\0';
	if (path[i] == '\0')
		return (NULL);
	pos += (i - pos) + 1;
	return (tmp);
}

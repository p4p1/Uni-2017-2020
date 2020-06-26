/*
** EPITECH PROJECT, 2017
** path.c
** File description:
** <..>
*/

#include "minishell2.h"

struct queue *get_path(struct queue *env)
{
	char	*path = my_strdup("PATH");
	int	i = 0;

	while (env) {
		i = 0;
		while (i < 5) {
			if (((char*)env->token)[i] == path[i])
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

	if (path[pos] == '\0')
		pos = 5;
	if (path == NULL || cmd == NULL)
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

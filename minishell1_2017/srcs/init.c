/*
** EPITECH PROJECT, 2017
** current-file-name
** File description:
** <..>
*/

#include "minishell.h"

static void *malloc_error(void)
{
	write(2, "[Err] malloc failed not enough memory.\n", 40);
	return (NULL);
}

static char **create_env_path(void)
{
	char	**path = malloc(sizeof(char *));

	if (path == NULL)
		return (NULL);
	return (path);
}

struct shell_info *init_shell(void)
{
	struct shell_info	*si = malloc(sizeof(struct shell_info));

	if (si == NULL)
		return (malloc_error());
	create_prompt(si);
	si->pwd = malloc(sizeof(char) * BUFSIZE);
	if (si->pwd == NULL)
		return (malloc_error());
	if (getcwd(si->pwd, BUFSIZE) == NULL) {
		write(2, "[Err] getcwd()\n", 17);
		return (NULL);
	}
	si->path = create_env_path();
	if (si->path == NULL)
		return (malloc_error());
	si->in_shell = 1;
	return (si);
}

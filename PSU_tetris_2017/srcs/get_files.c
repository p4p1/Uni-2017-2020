/*
** EPITECH PROJECT, 2017
** get_files.c
** File description:
** <..>
*/

#include "tetris.h"

static char *path_create(char *dir_name, char *name)
{
	char	*tmp = malloc(sizeof(char) *
			(my_strlen(dir_name) + my_strlen(name) + 2));
	int	i = 0;
	int	j = 0;

	if (tmp == NULL)
		return (NULL);
	for (i = 0; dir_name[i]; i++, j++)
		tmp[j] = dir_name[i];
	if (tmp[j - 1] != '/')
		tmp[j++] = '/';
	for (i = 0; name[i]; i++, j++)
		tmp[j] = name[i];
	tmp[j] = '\0';
	return (tmp);
}

static void set_no(struct queue *qu, int no)
{
	struct shapes	*el;

	while (qu) {
		el = qu->token;
		el->no = no;
		qu = qu->next;
	}
}

struct queue *get_files(char *dir_name)
{
	struct shapes	*shape = NULL;
	struct dirent	*dptr = NULL;
	struct queue	*qu = NULL;
	DIR		*dirp = NULL;
	char		*path = NULL;
	int		no = 0;

	if ((dirp = opendir(dir_name)) == NULL)
		return (NULL);
	while ((dptr = readdir(dirp)) != NULL) {
		path = path_create(dir_name, dptr->d_name);
		if (dptr->d_name[0] == '.')
			continue;
		if ((shape = get_shape_from_file(path)) == NULL)
			continue;
		qu = add_queue(qu, (void *)shape);
		++no;
	}
	closedir(dirp);
	set_no(qu, no);
	return (qu);
}

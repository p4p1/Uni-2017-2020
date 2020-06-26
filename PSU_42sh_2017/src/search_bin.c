/*
** EPITECH PROJECT, 2018
** search_bin.c
** File description:
** search the right path
*/

#include "my.h"

int count_path(char *str)
{
	int i = 0;
	int count = 1;

	while (str[i] != '\0') {
		if (str[i] == ':')
			count ++;
		i ++;
	}
	return (count);
}

void create_path(args *command, char *paths)
{
	int i = 0;
	int c = 0;
	int nb = count_path(paths);

	while (paths[i] != '/')
		i ++;
	for (int a = 0; a < nb; a ++) {
		command->path[a] = malloc(sizeof(char) * 30);
		if (command->path[a] == NULL)
			exit(84);
		while (paths[i] != ':' && paths[i] != '\0') {
			command->path[a][c] = paths[i];
			i ++;
			c ++;
		}
		command->path[a][c] = '/';
		i ++;
		c = 0;
	}
	return;
}

int search_path_line(args *command)
{
	int i = 0;
	int nb;

	while (command->env[i] != NULL
		&& strcmp("PATH", command->env[i]) != 1) {
		i ++;
	}
	if (command->env[i] == NULL)
		exit(84);
	nb = count_path(command->env[i]);
	command->path = malloc(sizeof(char *) * nb + 1);
	if (command->path == NULL)
		exit(84);
	create_path(command, command->env[i]);
	return (nb);
}

void check_path(args *command, int nb)
{
	DIR *rep = NULL;
	struct dirent *readfile = NULL;

	for (int i = 0; i < nb; i ++) {
		rep = opendir(command->path[i]);
		if (rep == NULL)
			return;
		readfile = readdir(rep);
		while (readfile != NULL
			&& strcmp(readfile->d_name ,command->filename) != 1) {
			readfile = readdir(rep);
		}
		if (readfile != NULL) {
			command->filename = concat(command->filename,
							command->path[i]);
			return;
		}
		if (closedir(rep) == -1)
			exit(84);
	}
	return;
}

void search_bin(args *command)
{
	int nb = 0;

	modif_name(command);
	nb = search_path_line(command);
	check_path(command, nb);
	return;
}

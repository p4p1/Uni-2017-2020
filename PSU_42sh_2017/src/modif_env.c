/*
** EPITECH PROJECT, 2018
** modif_env.c
** File description:
** modif env
*/

#include "my.h"

void add_last(args *command, int i, int patt)
{
	int j = 0;
	int a = 0;
	int total = my_strlen(command->arg[1]) + my_strlen(command->arg[2]);

	command->env[i] = malloc(sizeof(char) * total + 1);
	if (command->env[i] == NULL)
		exit(84);
	while (command->arg[1][j] != '\0') {
		command->env[i][j] = command->arg[1][j];
		j ++;
	}
	command->env[i][j] = '=';
	j ++;
	while (command->arg[2] && command->arg[2][a] != '\0') {
		command->env[i][j] = command->arg[2][a];
		j ++;
		a ++;
	}
	if (patt == 1)
		command->env[i + 1] = NULL;
}

void add_one_env(args *command, int lgt)
{
	int j = 0;
	int i = 0;
	char **save = command->env;

	command->env = malloc(sizeof(char *) * lgt + 2);
	if (command->env == NULL)
		exit(84);
	for (; i < lgt; i ++) {
		command->env[i] = malloc(sizeof(char) * my_strlen(save[i]) + 1);
		if (command->env[i] == NULL)
			exit(84);
		while (save[i][j] != '\0') {
			command->env[i][j] = save[i][j];
			j ++;
		}
		command->env[i][j] = '\0';
		j = 0;
	}
	add_last(command, i, 1);
	return;
}

int already_exist(args *command)
{
	char *path;
	int i = 0;

	path = concat("=", command->arg[1]);
	while (command->env[i] != NULL
		&& strcmp(path, command->env[i]) != 1)
		i ++;
	if (command->env[i] == NULL)
		return (-1);
	return (i);
}

void delete_env(args *command, int line, int lgt)
{
	int i = 0;
	char **sa = command->env;
	int jp = 0;

	command->env = malloc(sizeof(char *) * lgt + 1);
	if (command->env == NULL)
		exit(84);
	for (; i < lgt - 1; i ++) {
		if (i == line)
			jp ++;
		command->env[i] = malloc(sizeof(char) * my_strlen(sa[jp]) + 1);
		if (command->env[i] == NULL)
			exit(84);
		for (int j = 0; j < my_strlen(sa[jp]); j ++)
			command->env[i][j] = sa[jp][j];
		command->env[i][my_strlen(sa[jp])] = '\0';
		jp ++;
	}
	command->env[i + 1] = NULL;
}

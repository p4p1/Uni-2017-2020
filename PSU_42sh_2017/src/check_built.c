/*
** EPITECH PROJECT, 2018
** check_built.c
** File description:
** check built
*/

#include "my.h"
#include <stdio.h>

int strcmp(char *source, char *check)
{
	int i = 0;

	while (source[i] != '\0') {
		if (source[i] != check[i])
			return (0);
		i ++;
	}
	return (1);
}

int whole_strcmp(char *source, char *check)
{
	int i = 0;

	while (source[i] != '\0') {
		if (source[i] != check[i])
			return (0);
		i ++;
	}
	if (check[i] == '\0')
		return (1);
	else
		return (0);
}

int check_built(args *command)
{
	void (*do_cmd[5])(args *) = {my_cd, my_setenv,
					my_unsetenv, my_env, my_exit};
	char test[5][10] = {"cd", "setenv", "unsetenv", "env", "exit"};
	int i = 0;

	while (whole_strcmp(test[i], command->filename) != 1 && i < 5)
		i ++;
	if (i < 5) {
		do_cmd[i](command);
		return (0);
	} else if (command->filename[0] == '\0')
		return (0);
	else
		return (1);
}

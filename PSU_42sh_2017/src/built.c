/*
** EPITECH PROJECT, 2018
** built.c
** File description:
** all built fonctons
*/

#include "my.h"
#include <errno.h>

void my_cd(args *command)
{
	if (command->nb_args == 0) {
		get_pwd(command);
		go_home(command);
	} else if (command->arg[1][0] == '-' &&
			command->arg[1][1] == '\0') {
		chdir(command->cwd);
	} else {
		get_pwd(command);
		if (chdir(command->arg[1]) & ENOENT) {
			my_putstr(command->arg[1]);
			my_putstr(": Not a directory.\n");
		}
	}
	return;
}

void my_setenv(args *command)
{
	int i = 0;
	char *s = "setenv: Variable name must contain alphanumeric characters.";

	if (command->nb_args == 0) {
		my_env(command);
		return;
	}
	if (check_error_set(command) == -1) {
		my_putstr(s);
		my_putstr("\n");
		return;
	}
	if (already_exist(command) == -1) {
		while (command->env[i] != NULL)
			i ++;
		add_one_env(command, i);
	} else
		add_last(command, already_exist(command), 0);
	return;
}

void my_unsetenv(args *command)
{
	int i = 0;
	int total = 0;

	if (command->nb_args == 0) {
		my_putstr("unsetenv: Too few arguments.\n");
		return;
	}
	while (command->env[i] != NULL &&
		strcmp(command->arg[1], command->env[i]) != 1)
		i ++;
	if (command->env[i] == NULL)
		return;
	while (command->env[total] != NULL)
		total ++;
	delete_env(command, i, total);
	return;
}

void my_env(args *command)
{
	int i = 0;

	while (command->env[i] != NULL) {
		my_putstr(command->env[i]);
		my_putstr("\n");
		i ++;
	}
	return;
}

void my_exit(args *command)
{
	command->exit = 1;
	return;
}

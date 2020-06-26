/*
** EPITECH PROJECT, 2018
** go_cd.c
** File description:
** go back or home
*/

#include "my.h"

void go_home(args *command)
{
	char *str;
	int  i = 0;
	int cpt = 0;
	int j = 0;
	int g = 0;

	while (command->env[i] != NULL &&
		strcmp("PWD=", command->env[i]) != 1)
		i ++;
	if ((str = malloc(sizeof(char) * my_strlen(command->env[i]))) == NULL)
		exit(84);
	while (command->env[i][j] != '/')
		j ++;
	while (cpt != 3) {
		if (command->env[i][j] == '/')
			cpt ++;
		str[g] = command->env[i][j];
		g ++;
		j ++;
	}
	chdir(str);
}

void get_pwd(args *command)
{
	command->cwd = malloc(sizeof(char) * 100);
	if (command->cwd == NULL)
		exit(84);
	getcwd(command->cwd, 100);
	return;
}

void control_d(char *buff, int status)
{
	if (buff == NULL)
		exit(status);
	return;
}

void manage_sig(int sig)
{
	if (sig == SIGINT)
		my_putstr("\n$>");
	return;
}

int check_error_set(args *command)
{
	int i = 0;
	char *str = command->arg[1];

	while (str[i] != '\0') {
		if ((str[i] >= 65 && str[i] <= 90) ||
			(str[i] >= 97 && str[i] <= 122) ||
			(str[i] == '_'))
			i ++;
		else
			return (-1);
	}
	return (0);
}

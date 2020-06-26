/*
** EPITECH PROJECT, 2018
** do_command.c
** File description:
** do the command
*/

#include "my.h"

char *get_buff(char *buff)
{
	static int i = 0;
	int a = 0;
	char *tmp = malloc(sizeof(char) * my_strlen(buff));

	if (buff == NULL || tmp == NULL)
		return (NULL);
	tmp[0] = '\0';
	while (buff[i] && buff[i] != '\0') {
		if (buff[i] == ';') {
			i += 1;
			return (tmp);
		}
		tmp[a] = buff[i];
		a ++;
		i ++;
	}
	if (tmp[0] == '\0') {
		i = 0;
		return (NULL);
	}
	return (tmp);
}

int check_pipe(char *test)
{
	int i = 0;

	while (test[i] != '\0') {
		if (test[i] == '|')
			return (1);
		else
			i ++;
	}
	return (0);
}

int do_struct_command(args *command, char *buff, char **envp, int *status)
{
	char *test = NULL;

	while ((test = get_buff(buff)) != NULL) {
		test = make_good(test);
		if (check_pipe(test) == 1)
			do_pipe(test, envp);
		else {
			create_struct(command, test, envp, 0);
			if (check_built(command) != 0)
				execut_fork(command, test);
			wait(status);
			if (command->exit == 1)
				return (0);
		}
	}
	return (1);
}

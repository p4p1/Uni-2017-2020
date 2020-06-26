/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** it's my main
*/

#include "my.h"
#include "errno.h"

void malloc_double_str(args *command, char *str)
{
	int j = 0;
	int malloc_nb = 0;

	command->arg = malloc(sizeof(char *) * (command->nb_args + 2));
	if (command->arg == NULL)
		exit(84);
	for (int i = 0; i < command->nb_args + 1; i ++) {
		while (str[j] != ' ' && str[j] != '\0') {
			malloc_nb ++;
			j ++;
		}
		command->arg[i] = malloc(sizeof(char) * malloc_nb + 1);
		if (command->arg[i] == NULL)
			exit(84);
		malloc_nb = 0;
	}
	command->arg[command->nb_args + 1] = NULL;
	j = 0;
	return;
}

void create_arg(args *command, char *str)
{
	int j = 0;
	int a = 0;

	command->exit = 0;
	malloc_double_str(command, str);
	for (int i = 0; i < command->nb_args + 1; i ++) {
		while (str[j] != ' ' && str[j] != '\0' && str[j] != '\n') {
			command->arg[i][a] = str[j];
			j ++;
			a ++;
		}
		j ++;
		a = 0;
	}
	return;
}

void create_struct(args *command, char *str, char **envp, int ch)
{
	int i = 0;
	static int reset = 0;

	command->envini = envp;
	command->nb_args = 0;
	if (reset == 0 && ch == 0) {
		command->env = envp;
		reset ++;
	}
	command->filename = malloc(sizeof(char) * my_strlen(str));
	if (command->filename == NULL)
		exit(84);
	while (str[i] != ' ' && str[i] != '\0' && str[i] != '\n') {
		command->filename[i] = str[i];
		i ++;
	}
	command->filename[i] = '\0';
	while (str[i] != '\0' && str[i] != '\n')
		if (str[i++] == ' ')
			command->nb_args ++;
	create_arg(command, str);
}

void execut_fork(args *command, char *str)
{
	command->fork = fork();
	if (command->fork == 0) {
		command->fork = 1;
		search_bin(command);
		if (access(command->filename, F_OK) == 0) {
			execve(command->filename, command->arg, command->env);
			perror(command->filename);
		} else {
			my_putstr(str);
			my_putstr(": Command not found.\n");
		}
		exit(0);
	}
	return;
}

int main(int ac, char **av, char **envp)
{
	args command;
	char *buff;
	int status = 0;
	int err = 0;

	(void)ac;
	(void)av;
	status = handle_signal(status);
	while (1) {
		my_putstr("$> ");
		buff = get_the_line(&err, status);
		if (err == -1)
			return (status);
		control_d(buff, status);
		buff = make_good(buff);
		if (do_struct_command(&command, buff, envp, &status) == 0)
			return (0);
	}
	return (0);
}

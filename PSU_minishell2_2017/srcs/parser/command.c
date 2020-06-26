/*
** EPITECH PROJECT, 2017
** command.c
** File description:
** <..>
*/

#include "minishell2.h"

static void set_path(struct queue *qu)
{
	char	buffer[1024];
	char	*path = NULL;

	getcwd(buffer, 1024);
	path = malloc(sizeof(char) * (4 + my_strlen(buffer) + 1));
	my_strcpy(path, "PWD=");
	my_strcat(path, buffer);
	while (qu) {
		if (my_strstr(qu->token, "PWD="))
			break;
		qu = qu->next;
	}
	(qu) ? qu->token = path : add_queue(qu, path);
}

static int cd(char **token, struct queue **env)
{
	char	cd_str[3] = "cd";
	int	i = 0;

	while (token[0][i] != '\0' && i < 2) {
		if (token[0][i] == cd_str[i])
			i++;
		else
			break;
	}
	if (i == 2 && token[0][i] == '\0') {
		change_path(token, env);
		set_path(*env);
		return (1);
	}
	return (0);
}

static int env_in(char *token, struct queue *tmp)
{
	char	env_str[4] = "env";
	int	i = 0;

	while (token[i] != '\0' && i < 4) {
		if (token[i] == env_str[i])
			i++;
		else
			break;
	}
	if (i == 3 && token[i] == '\0') {
		while (tmp) {
			my_printf("%s\n", tmp->token);
			tmp = tmp->next;
		}
		return (1);
	}
	return (0);
}

static int exit_inner(char *token)
{
	char	exit_str[5] = "exit";
	int	i = 0;

	while (token[i] != '\0' && i < 5) {
		if (token[i] == exit_str[i])
			i++;
		else
			break;
	}
	if (i == 4 && token[i] == '\0') {
		exit(0);
	}
	return (0);
}

int inier_command(char **cmd, struct queue **env)
{
	if (cd(cmd, env))
		return (0);
	if (exit_inner(*cmd))
		return (0);
	if (env_in(*cmd, *env))
		return (0);
	if (setenv_inner(cmd, env))
		return (0);
	if (unsetenv_inner(cmd, env))
		return (0);
	return (1);
}

/*
** EPITECH PROJECT, 2017
** command.c
** File description:
** <..>
*/

#include "minishell.h"

static void set_path(struct shell_info *si)
{
	char	buffer[1024];
	char	*path = NULL;
	struct queue *qu = si->envi;

	getcwd(buffer, 1024);
	path = malloc(sizeof(char) * (4 + my_strlen(buffer) + 1));
	my_strcpy(path, "PWD=");
	my_strcat(path, buffer);
	while (qu) {
		if (my_strstr(qu->token, "PWD="))
			break;
		qu = qu->next;
	}
	(qu) ? qu->token = path : add_queue(&si->envi, path);
}

static int cd(struct shell_info *si)
{
	char	cd_str[3] = "cd";
	int	i = 0;

	while (si->token[0][i] != '\0' && i < 2) {
		if (si->token[0][i] == cd_str[i])
			i++;
		else
			break;
	}
	if (i == 2 && si->token[0][i] == '\0') {
		change_path(si);
		set_path(si);
		return (1);
	}
	return (0);
}

static int env(struct shell_info *si)
{
	char	env_str[4] = "env";
	int	i = 0;
	struct queue	*tmp = si->envi;

	while (si->token[0][i] != '\0' && i < 4) {
		if (si->token[0][i] == env_str[i])
			i++;
		else
			break;
	}
	if (i == 3 && si->token[0][i] == '\0') {
		while (tmp) {
			my_printf("%s\n", tmp->token);
			tmp = tmp->next;
		}
		return (1);
	}
	return (0);
}

static int exit_inner(struct shell_info *si)
{
	char	exit_str[5] = "exit";
	int	i = 0;

	while (si->token[0][i] != '\0' && i < 5) {
		if (si->token[0][i] == exit_str[i])
			i++;
		else
			break;
	}
	if (i == 4 && si->token[0][i] == '\0') {
		exit(0);
	}
	return (0);
}

int inier_command(struct shell_info *si)
{
	if (cd(si))
		return (0);
	if (exit_inner(si))
		return (0);
	if (env(si))
		return (0);
	if (setenv_inner(si))
		return (0);
	if (unsetenv_inner(si))
		return (0);
	return (1);
}

/*
** EPITECH PROJECT, 2017
** env.c
** File description:
** <..>
*/

#include "minishell2.h"

static int add_to_env(struct queue **envi, char **token)
{
	struct queue	*qu = *envi;
	char		*str = NULL;

	if (token[1] == NULL)
		return (0);
	while (qu) {
		if (my_strstr(qu->token, token[1]))
			break;
		qu = qu->next;
	}
	str = malloc(sizeof(char) * (my_strlen(token[1]) +
				my_strlen(token[2]) + 3));
	if (str == NULL || my_strcpy_alphanum(str, token[1]) == NULL)
		return (-1);
	my_strcat(str, "=");
	my_strcat(str, (token[2]) ? token[2] : "");
	if (qu)
		qu->token = str;
	else
		*envi = add_queue(*envi, str);
	return (0);
}

static int remove_from_env(struct queue **envi, char **token)
{
	struct queue	*qu = *envi;
	struct queue	*tmp = NULL;

	if (token[1] == NULL)
		return (-1);
	while (qu) {
		if (my_strstr(qu->token, token[1])) {
			break;
		}
		tmp = qu;
		qu = qu->next;
	}
	if (qu) {
		if (qu && tmp) {
			tmp->next = qu->next;
		} else {
			*envi = NULL;
		}
	}
	return (0);
}

int unsetenv_inner(char **token, struct queue **envi)
{
	char	cd_str[9] = "unsetenv";
	int	i = 0;

	while (token[0][i] != '\0' && i < 8) {
		if (token[0][i] == cd_str[i])
			i++;
		else
			break;
	}
	if (i == 8) {
		if (remove_from_env(envi, token) < 0)
			my_printf("unsetenv: Too few arguments.\n");
		return (1);
	}
	return (0);
}

int setenv_inner(char **token, struct queue **envi)
{
	char	cd_str[7] = "setenv";
	int	i = 0;

	while (token[0][i] != '\0' && i < 6) {
		if (token[0][i] == cd_str[i])
			i++;
		else
			break;
	}
	if (i == 6) {
		if (add_to_env(envi, token) < 0)
			my_printf("setenv: Variable name must contain"
					"alphanumeric characters.\n");
		return (1);
	}
	return (0);
}

char *get_home(struct queue *qu)
{
	char	*tmp = NULL;
	char	*home = my_strdup("HOME=");

	while (qu) {
		if (qu->token != NULL && my_strstr(qu->token, home))
			break;
		qu = qu->next;
	}
	if (qu)
		tmp = my_strdup(qu->token + 5);
	return (tmp);
}

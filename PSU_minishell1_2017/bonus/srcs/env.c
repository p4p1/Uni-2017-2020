/*
** EPITECH PROJECT, 2017
** env.c
** File description:
** <..>
*/

#include "minishell.h"

static int add_to_env(struct shell_info *si)
{
	struct queue	*qu = si->envi;
	char		*str = NULL;

	if (si->token[1] == NULL)
		return (-1);
	do {
		if (my_strstr(qu->token, si->token[1]))
			break;
		qu = qu->next;
	} while (qu);
	str = malloc(sizeof(char) * (my_strlen(si->token[1]) +
				my_strlen(si->token[2]) + 2));
	if (str == NULL)
		return (-1);
	my_strcpy(str, si->token[1]);
	my_strcat(str, "=");
	my_strcat(str, (si->token[2]) ? si->token[2] : "");
	(qu) ? qu->token = str : add_queue(&si->envi, str);
	return (0);
}

static int remove_from_env(struct shell_info *si)
{
	struct queue	*qu = si->envi;
	struct queue	*tmp = si->envi;

	if (si->token[1] == NULL)
		return (-1);
	while (qu) {
		if (my_strstr(qu->token, si->token[1])) {
			tmp->next = qu->next;
			free(qu);
			break;
		}
		tmp = qu;
		qu = qu->next;
	}
	return (0);
}

int unsetenv_inner(struct shell_info *si)
{
	char	cd_str[9] = "unsetenv";
	int	i = 0;

	while (si->token[0][i] != '\0' && i < 8) {
		if (si->token[0][i] == cd_str[i])
			i++;
		else
			break;
	}
	if (i == 8) {
		if (remove_from_env(si) < 0)
			my_printf("unsetenv: Too few arguments.\n");
		return (1);
	}
	return (0);
}

int setenv_inner(struct shell_info *si)
{
	char	cd_str[7] = "setenv";
	int	i = 0;

	while (si->token[0][i] != '\0' && i < 6) {
		if (si->token[0][i] == cd_str[i])
			i++;
		else
			break;
	}
	if (i == 6) {
		if (add_to_env(si) < 0)
			my_printf("setenv: Variable name must contain"
					"alphanumeric characters.\n");
		return (1);
	}
	return (0);
}

/*
** EPITECH PROJECT, 2017
** count.c
** File description:
** <..>
*/

#include "minishell2.h"

int is_separator(char ch)
{
	char	*str = my_strdup(SEPARATOR);

	for (int i = 0; str[i]; i++) {
		if (str[i] == ch) {
			free(str);
			return (1);
		}
	}
	free(str);
	return (0);
}

int count_args(char *str)
{
	int	no = 1;
	int	i = 0;

	while (str[i] && !is_separator(str[i])) {
		if ((str[i] == ' ' || str[i] == '\t') &&
				(str[i + 1] != ' ' || str[i + 1] != '\t') &&
				!is_separator(str[i + 1]))
			++no;
		++i;
	}
	return (no);
}

int next_arg(char *str)
{
	int	no = 0;

	while (str[no] && str[no] != ' ' && str[no] != '\t' &&
			!is_separator(str[no]))
		no++;
	return (no);
}

int skip_tabs_space(char *str)
{
	int	no = 0;

	while (str[no] && (str[no] == ' ' || str[no] == '\t'))
		no++;
	return (no);
}

/*
** EPITECH PROJECT, 2017
** count.c
** File description:
** <..>
*/

#include "minishell.h"

int arg_no(char *buffer)
{
	int	number = 1;

	for (int i = 0; buffer[i]; i++)
		if (buffer[i] == ' ')
			number++;
	return (number + 1);
}

char *my_strdup_ln_space(char *buffer, int *pos)
{
	char	*tmp = (char *)malloc(sizeof(char) * my_strlen(buffer));
	int	j = 0;
	int	i = 0;

	if (tmp == NULL)
		return (NULL);
	for (i = *pos; i < my_strlen(buffer) && buffer[i] != ' '; i++) {
		tmp[j] = buffer[i];
		++j;
	}
	*pos = ++i;
	tmp[j] = '\0';
	return(tmp);
}

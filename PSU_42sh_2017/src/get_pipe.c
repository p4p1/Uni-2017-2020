/*
** EPITECH PROJECT, 2018
** get_pipe.c
** File description:
** get pipe
*/

#include "my.h"

int jump_pipe(int i, char *str)
{
	while (str[i] == '|') {
		i ++;
	}
	return (i);
}

char *get_pipe(char *str)
{
	static int i = 0;
	char *tmp = malloc(sizeof(char) * my_strlen(str));
	int a = 0;

	if (str == NULL || tmp == NULL)
		return (NULL);
	tmp[0] = '\0';
	while (str[i] && str[i] != '\0') {
		if (str[i] == '|') {
			i = jump_pipe(i, str);
			return (tmp);
		}
		tmp[a] = str[i];
		a ++;
		i ++;
	}
	i = 0;
	return (tmp);
}

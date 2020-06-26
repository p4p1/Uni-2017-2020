/*
** EPITECH PROJECT, 2018
** make_good.c
** File description:
** destroy \t and space line formatting
*/

#include "my.h"


int check_string(char *str, int i)
{
	while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
		i ++;
	return (i);
}

int check_end_good(char *str, int i)
{
	while (str[i] != '\0') {
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			return (0);
		i ++;
	}
	return (1);
}

char *make_good(char *str)
{
	int i = 0;
	int a = 0;
	char *final = malloc(sizeof(char) * my_strlen(str));

	if (str == NULL)
		return (NULL);
	while (str[i] != '\0') {
		i = check_string(str, i);
		while ((str[i] != '\t' && str[i] != ' ') && str[i] != '\0') {
			final[a] = str[i];
			i ++;
			a ++;
		}
		if (str[i] == '\0')
			final[a] = '\0';
		else if (check_end_good(str, i) == 0) {
			final[a] = ' ';
			a ++;
		}
	}
	return (final);
}

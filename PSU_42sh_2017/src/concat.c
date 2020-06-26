/*
** EPITECH PROJECT, 2018
** concat.c
** File description:
** concatene my string
*/

#include <unistd.h>
#include "my.h"

char *concat(char *source, char *bin)
{
	char *final = malloc(sizeof(char) * (my_strlen(source) + 6));
	int a = 0;
	int i = 0;

	if (final == NULL)
		exit (84);
	while (bin[i] != '\0') {
		final[i] = bin[i];
		i ++;
	}
	while (source[a] != '\0') {
		final[i] = source[a];
		a ++;
		i ++;
	}
	return (final);
}

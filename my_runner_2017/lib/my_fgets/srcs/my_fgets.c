/*
** EPITECH PROJECT, 2017
** my_fgets.c
** File description:
** the fgets function
*/

#include "my_fgets.h"

char my_getchar_fd(unsigned int stream)
{
	char	ch = 0;

	read(stream, &ch, 1);
	return (ch);
}

char *fgets(char *s, int size, unsigned int stream)
{
	int	i = 0;
	char	ch = 1;

	while (i < size)
		s[i++] = 0;
	i = 0;
	while (i < size && ch != '\n') {
		ch = my_getchar_fd(stream);
		s[i++] = ch;
	}
	return (s);
}

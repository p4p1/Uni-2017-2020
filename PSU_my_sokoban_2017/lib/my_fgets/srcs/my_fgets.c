/*
** EPITECH PROJECT, 2017
** my_fgets.c
** File description:
** the fgets function
*/

#include "my_fgets.h"

static char my_getchar_fd(unsigned int stream)
{
	char	ch = 0;

	if (read(stream, &ch, 1) == 0)
		return (0);
	return (ch);
}

char *my_fgets(char *s, int size, unsigned int stream)
{
	int	i = 0;
	char	ch = 0;

	while (i < size && ch != '\n') {
		ch = my_getchar_fd(stream);
		if (ch == 0)
			break;
		s[i++] = ch;
	}
	s[i] = '\0';
	return (s);
}

/*
** EPITECH PROJECT, 2017
** pos.c
** File description:
** <..>
*/

#include "tetris.h"

int dot_pos(char *fname)
{
	int	i = 0;

	while (fname[i]) {
		if (fname[i] == '.')
			return (i);
		++i;
	}
	return (0);
}

int skip_slash(char *fname)
{
	int	i = 0;

	while (fname[i]) {
		if (fname[i] == '/')
			return (i + 1);
		++i;
	}
	return (0);
}

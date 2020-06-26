/*
** EPITECH PROJECT, 2017
** valid_line.c
** File description:
** <..>
*/

#include "tetris.h"

int is_line_size(char *line)
{
	int	no = 1;
	int	in_space = 0;
	int	i = 0;

	for (i = 0; line[i]; i++) {
		if (line[i] == ' ') {
			no += (in_space == 0) ? 1 : 0;
			in_space = 1;
			continue;
		}
		if (!(line[i] >= '0' && line[i] <= '9'))
			break;
		in_space = 0;
	}
	if (no == 3)
		return (1);
	return (0);
}

int is_tetrimino_line(char *line)
{
	for (int i = 0; line[i]; i++) {
		if (line[i] != ' ' && line[i] != '*')
			return (0);
	}
	return (1);
}

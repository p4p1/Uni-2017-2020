/*
** EPITECH PROJECT, 2017
** end.c
** File description:
** <..>
*/

#include "connect4.h"

static int is_over_bis(struct game *gm, int i)
{
	for (int j = 0; j < gm->width; j++) {
		if (gm->map[i][j] == '.')
			return (1);
	}
	return (0);
}

int is_over(struct game *gm)
{
	for (int i = 0; i < gm->height; i++) {
		if (is_over_bis(gm, i))
			return (0);
	}
	return (1);
}

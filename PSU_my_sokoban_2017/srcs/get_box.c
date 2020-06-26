/*
** EPITECH PROJECT, 2017
** get_box.c
** File description:
** <..>
*/

#include "my_sokoban.h"

int get_box(struct game *gm, int x, int y)
{
	unsigned int	i = 0;

	for (i = 0; i < gm->no_box; i++) {
		if (gm->bx[i]->x == x && gm->bx[i]->y == y) {
			return (i);
		}
	}
	return (-1);
}

static int top_left(struct game *gm, int i)
{
	if (gm->map[gm->bx[i]->y - 1][gm->bx[i]->x] == '#' &&
		gm->map[gm->bx[i]->y][gm->bx[i]->x - 1] == '#'
		&& gm->bx[i]->in_box != 1) {
		return (1);
	}
	return (0);
}

static int top_right(struct game *gm, int i)
{
	if (gm->map[gm->bx[i]->y + 1][gm->bx[i]->x] == '#' &&
		gm->map[gm->bx[i]->y][gm->bx[i]->x + 1] == '#'
		&& gm->bx[i]->in_box != 1) {
		return (1);
	}
	return (0);
}

int is_blok(struct game *gm)
{
	unsigned int	no = 0;

	for (unsigned int i = 0; i < gm->no_box; i++) {
		if (top_left(gm, i))
			no++;
		if (top_right(gm, i))
			no++;
		if (gm->map[gm->bx[i]->y + 1][gm->bx[i]->x] == '#' &&
			gm->map[gm->bx[i]->y][gm->bx[i]->x - 1] == '#'
			&& gm->bx[i]->in_box != 1) {
			no++;
		}
		if (gm->map[gm->bx[i]->y - 1][gm->bx[i]->x] == '#' &&
			gm->map[gm->bx[i]->y][gm->bx[i]->x + 1] == '#'
			&& gm->bx[i]->in_box != 1) {
			no++;
		}
	}
	return ((no == gm->no_box)? 1 : 0);
}

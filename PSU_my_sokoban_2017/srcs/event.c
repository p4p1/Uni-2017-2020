/*
** EPITECH PROJECT, 2017
** event.c
** File description:
** <..>
*/

#include "my_sokoban.h"

static void reset(struct game *gm)
{
	unsigned int	i = 0;

	if (gm->p1->in_box) {
		gm->map[gm->p1->y][gm->p1->x] = 'O';
		gm->p1->in_box = 0;
	} else {
		gm->map[gm->p1->y][gm->p1->x] = ' ';
	}
	gm->p1->x = gm->p1->initial_x;
	gm->p1->y = gm->p1->initial_y;
	for (i = 0; i < gm->no_box; i++) {
		if (gm->bx[i]->in_box) {
			gm->map[gm->bx[i]->y][gm->bx[i]->x] = 'O';
			gm->bx[i]->in_box = 0;
		} else {
			gm->map[gm->bx[i]->y][gm->bx[i]->x] = ' ';
		}
		gm->bx[i]->x = gm->bx[i]->initial_x;
		gm->bx[i]->y = gm->bx[i]->initial_y;
	}
}

int handle_event(char ch, struct game *gm)
{
	if (ch == 67)
		gm->p1->move_pos(gm->p1, gm, 1, 0);
	if (ch == 68)
		gm->p1->move_pos(gm->p1, gm, -1, 0);
	if (ch == 66)
		gm->p1->move_pos(gm->p1, gm, 0, 1);
	if (ch == 65)
		gm->p1->move_pos(gm->p1, gm, 0, -1);
	if (ch == ' ')
		reset(gm);
	if (ch == 'q')
		return (-1);
	return (0);
}

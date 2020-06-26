/*
** EPITECH PROJECT, 2017
** replace.c
** File description:
** <..>
*/

#include "connect4.h"

int rep_right(struct game *gm, int posx, int posy)
{
	int	i = 0;

	for (i = 0; i < 4 && posx + i < gm->width; i++) {
		gm->map[posy][posx + i] = gm->end;
	}
	return (1);
}

int rep_left(struct game *gm, int posx, int posy)
{
	int	i = 0;

	for (i = 0; i < 4 && posx - i >= 0; i++) {
		gm->map[posy][posx - i] = gm->end;
	}
	return (1);
}

int rep_down(struct game *gm, int posx, int posy)
{
	int	i = 0;

	for (i = 0; i < 4 && posy + i < gm->height; i++) {
		gm->map[posy + i][posx] = gm->end;
	}
	return (1);
}

int diag_rdow(struct game *gm, int posx, int posy)
{
	int	i = 0;
	int	j = 0;

	for (i = 0, j = 0; i < 4 && posx + i < gm->width
			&& posy + j < gm->height; i++, j++)
		gm->map[posy + i][posx + j] = gm->end;
	return (1);
}

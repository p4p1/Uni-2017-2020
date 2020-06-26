/*
** EPITECH PROJECT, 2017
** check.c
** File description:
** <..>
*/

#include "connect4.h"

static int side(struct game *gm, int posx, int posy, char ch)
{
	int	i = 0;

	for (i = 0; i < 4 && posx + i < gm->width; i++) {
		if (gm->map[posy][posx + i] != ch)
			break;
	}
	if (i == 4)
		return (rep_right(gm, posx, posy));
	for (i = 0; i < 4 && posx - i >= 0; i++) {
		if (gm->map[posy][posx - i] != ch)
			break;
	}
	if (i == 4)
		return (rep_left(gm, posx, posy));
	for (i = 0; i < 4 && posy + i < gm->height; i++) {
		if (gm->map[posy + i][posx] != ch)
			break;
	}
	if (i == 4)
		return (rep_down(gm, posx, posy));
	return (0);
}

static int diag_right(struct game *gm, int posx, int posy, char ch)
{
	int	i = 0;
	int	j = 0;

	for (i = 0, j = 0; i < 4 && posx + i < gm->width
			&& posy + j < gm->height; i++, j++)
		if (gm->map[posy + j][posx + i] != ch)
			break;
	if (i == 4)
		return (diag_rdow(gm, posx, posy));
	for (i = 0, j = 0; i < 4 && posx + i < gm->width
			&& posy - j > 0; i++, j++)
		if (gm->map[posy - j][posx + i] != ch)
			break;
	if (i == 4)
		return (diag_rup(gm, posx, posy));
	return (0);
}

static int diag_left(struct game *gm, int posx, int posy, char ch)
{
	int	i = 0;
	int	j = 0;

	for (i = 0, j = 0; i < 4 && posx - i > 0
			&& posy - j > 0; i++, j++)
		if (gm->map[posy - j][posx - i] != ch)
			break;
	if (i == 4)
		return (diag_lup(gm, posx, posy));
	for (i = 0, j = 0; i < 4 && posx - i > 0
			&& posy + j < gm->height; i++, j++)
		if (gm->map[posy + j][posx - i] != ch)
			break;
	if (i == 4)
		return (diag_ldow(gm, posx, posy));
	return (0);
}

int is_winner(struct game *gm, int posx, int posy, char ch)
{
	if (side(gm, posx, posy, ch))
		return (1);
	if (diag_right(gm, posx, posy, ch))
		return (1);
	if (diag_left(gm, posx, posy, ch))
		return (1);
	return (0);
}

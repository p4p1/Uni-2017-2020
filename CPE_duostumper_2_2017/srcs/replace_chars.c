/*
** EPITECH PROJECT, 2017
** replace_chars.c
** File description:
** <..>
*/

#include "connect4.h"

int diag_rup(struct game *gm, int posx, int posy)
{
	int	i = 0;
	int	j = 0;

	for (i = 0, j = 0; i < 4 && posx + i < gm->width
			&& posy - j > 0; i++, j++)
		gm->map[posy + i][posx - j] = gm->end;
	return (1);
}

int diag_lup(struct game *gm, int posx, int posy)
{
	int	i = 0;
	int	j = 0;

	for (i = 0, j = 0; i < 4 && posx - i > 0
			&& posy - j > 0; i++, j++)
		gm->map[posy - i][posx - j] = gm->end;
	return (1);
}

int diag_ldow(struct game *gm, int posx, int posy)
{
	int	i = 0;
	int	j = 0;

	for (i = 0, j = 0; i < 4 && posx - i > 0
			&& posy + j < gm->height; i++, j++)
		gm->map[posy - i][posx - j] = gm->end;
	return (1);
}

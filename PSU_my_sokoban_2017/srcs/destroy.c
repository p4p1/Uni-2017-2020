/*
** EPITECH PROJECT, 2017
** destroy.h
** File description:
** <..>
*/

#include "my_sokoban.h"

void destroy(struct game *gm)
{
	unsigned int	i = 0;

	if (gm != NULL) {
		for (i = 0; i < gm->no_box; i++) {
			if (gm->bx != NULL && gm->bx[i] != NULL)
				free(gm->bx[i]);
		}
		if (gm->bx != NULL)
			free(gm->bx);
		if (gm->p1 != NULL)
			free(gm->p1);
	}
	endwin();
}

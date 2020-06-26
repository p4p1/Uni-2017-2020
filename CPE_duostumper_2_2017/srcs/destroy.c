/*
** EPITECH PROJECT, 2017
** destroy.c
** File description:
** <..>
*/

#include "connect4.h"

void *destroyer(struct game *gm)
{
	if (gm->map != NULL) {
		for (int i = 0 ; i < gm->height; i++) {
			free(gm->map[i]);
		}
		free(gm->map);
	}
	free(gm);
	return (NULL);
}

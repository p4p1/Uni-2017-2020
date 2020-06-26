/*
** EPITECH PROJECT, 2017
** destroy.c
** File description:
** <..>
*/

#include "my_hunter.h"

void destroy_all(struct game *s_game)
{
	int	i = 0;

	for (i = 0; i < 3; i++) {
		free(s_game->ducks[i]->sprite);
		sfTexture_destroy(s_game->ducks[i]->texture);
		free(s_game->ducks[i]->size);
		free(s_game->ducks[i]);
	}
	sfRenderWindow_destroy(s_game->window);
}

/*
** EPITECH PROJECT, 2017
** event.c
** File description:
** <..>
*/

#include "my_hunter.h"

static void colided(struct game *s_game, sfEvent event)
{
	int	i = 0;
	for (i = 0; i < NUMBER_OF_DUCKS; i++) {
		if (s_game->ducks[i]->colision(s_game->ducks[i],
				event.mouseButton.x, event.mouseButton.y)) {
			s_game->score++;
		}
	}
}

int event_handler(struct game *s_game)
{
	sfEvent	event;

	while (sfRenderWindow_pollEvent(s_game->window, &event)) {
		if (event.type == sfEvtClosed)
			return (-1);
		if (event.type == sfEvtMouseButtonPressed) {
			colided(s_game, event);
		}
	}
	return (0);
}

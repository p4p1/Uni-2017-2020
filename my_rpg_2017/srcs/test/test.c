/*
** EPITECH PROJECT, 2017
** test.c
** File description:
** <..>
*/

#include "my_rpg.h"

static int event_handler(game_t *gm, character_t *hero, object_t *obj)
{
	int	no = -1;

	hero->speed = 1;
	while (sfRenderWindow_pollEvent(gm->wd, &gm->event)) {
		if (gm->event.type == sfEvtClosed ||
				gm->event.key.code == sfKeyEscape)
			sfRenderWindow_close(gm->wd);
		if (gm->event.key.code == sfKeySpace)
			return (1);
		player_movement(hero, gm, obj);
		if (detecte_press(sfKeyEscape, gm) == 1) {
			gm->stuff[0]->status = 0;
			actual_scene = 1;
		}
	}
	return (no);
}

int test(game_t *gm)
{
	int			no = -1;

	while (sfRenderWindow_isOpen(gm->wd) && no < 0) {
		no = event_handler(gm, gm->hero, gm->new_obj);
		disp_map(gm);
	}
	return (no);
}

/*
** EPITECH PROJECT, 2017
** display.c
** File description:
** <..>
*/

#include "my_rpg.h"

void disp_map(game_t *gm)
{
	static struct __entity__	*qu = NULL;

	if (!qu)
		qu = create_map(0, 0);
	if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue)
		qu->move(qu, 0, gm->hero->speed);
	if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
		qu->move(qu, 0, gm->hero->speed * -1);
	if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue)
		qu->move(qu, gm->hero->speed * -1, 0);
	if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
		qu->move(qu, gm->hero->speed, 0);
	qu->draw(qu, gm->wd);
	sfRenderWindow_drawRectangleShape(gm->wd, gm->hero->trainer, NULL);
}

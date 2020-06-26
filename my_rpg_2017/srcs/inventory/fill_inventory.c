/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** add and remove of items in inventory
*/

#include "my_rpg.h"

int detecte_press(sfKeyCode keyboard, game_t *gm)
{
	static int status = -1;
	static int block = 0;
	static sfKeyCode last_key = 0;

	if (keyboard != last_key) {
		status = -1;
		block = 0;
	}
	if (sfKeyboard_isKeyPressed(keyboard) == sfTrue && block == 0) {
		status = 1;
		block = 1;
		last_key = keyboard;
	} else if (sfKeyboard_isKeyPressed(keyboard) == sfTrue && block == 1) {
		status = -1;
	}
	if (sfKeyboard_isKeyPressed(keyboard) == sfFalse && block == 1) {
		status = -1;
		block = 0;
		last_key = 0;
	}
	return (status);
}

static void check_inventory(game_t *gm, item_t *items, int i)
{
	sfVector2f pos;
	int index = 0;

	if (gm->stuff[items->type]->items[i]->stock == 0) {
		while (my_strcmp(gm->stuff[items->type]->items[index]->name,
			 "Fermer") != 0)
			index++;
		pos = sfText_getPosition(gm->stuff[items->type]->
			items[index]->sfname);
		sfText_setPosition(gm->stuff[items->type]->items[i]->sfname,
			pos);
		if (pos.y == 50)
			gm->stuff[items->type]->selector->idx = i;
		pos.y += 60;
		sfText_setPosition(gm->stuff[items->type]->items[index]->sfname
			, pos);
	}
}

void fill_inventory(game_t *gm, item_t *items)
{
	int i = 0;

	while (i < 12) {
		if (my_strcmp(gm->stuff[items->type]->items[i]->name,
			items->name) == 0) {
			check_inventory(gm, items, i);
			gm->stuff[items->type]->items[i]->stock += 1;
		}
		i++;
	}
}

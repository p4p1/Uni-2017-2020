/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** about pause menu in game
*/

#include "my_rpg.h"

sfRectangleShape *create_menu(void)
{
	sfRectangleShape *inventory = sfRectangleShape_create();
	sfVector2f pos = {1600.0, 100.0};
	sfVector2f size = {320.0, 680.0};

	sfRectangleShape_setSize(inventory, size);
	sfRectangleShape_setPosition(inventory, pos);
	sfRectangleShape_setOutlineColor(inventory, sfGreen);
	sfRectangleShape_setOutlineThickness(inventory, 2);
	return (inventory);
}

void open_menu(game_t *gm, inventory_t *stuff)
{
	static int inventory_status = -1;
	static int status_bis = 0;

	if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue && status_bis == 0) {
		inventory_status = inventory_status * (-1);
		status_bis = 1;
	}
	if (gm->event.type == sfEvtKeyReleased && status_bis == 1)
		status_bis = 0;
	if (inventory_status == 1)
		sfRenderWindow_drawRectangleShape(gm->wd, gm->menu, NULL);
}

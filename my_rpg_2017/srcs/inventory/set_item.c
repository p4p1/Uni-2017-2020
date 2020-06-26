/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** set item positions
*/

#include "../../include/my_rpg.h"

int set_pos_new_item(item_t *item, inventory_t *inventory)
{
	sfVector2f search_pos = {0, 0};

	for (int i = 0; inventory->items[i]->stock != 0 &&
		inventory->items != NULL; i++) {
		search_pos = sfText_getPosition(inventory->items[i]->sfname);
	}
	search_pos.y = search_pos.y + 45;
	sfText_setPosition(item->sfname, search_pos);
	return (0);
}

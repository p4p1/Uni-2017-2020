/*
** EPITECH PROJECT, 2017
** destroyer.c
** File description:
** <..>
*/

#include "my_rpg.h"

static void destroy_inventory(inventory_t *inventory)
{
	destroy_item_selector(inventory->selector);
	for (int i = 0; i < 12; i++) {
		if (inventory->items[i]->name != NULL)
			free(inventory->items[i]->name);
		if (inventory->items[i]->sfname != NULL)
			sfText_destroy(inventory->items[i]->sfname);
		free(inventory->items[i]);
	}
	free(inventory);
}

static void destroy_character(game_t *gm)
{
	sfRectangleShape_destroy(gm->hero->trainer);
	sfClock_destroy(gm->hero->clock);

	for (int j = 0; j < 8; j++) {
		destroy_inventory(gm->stuff[j]);
	}
	for (int i = 0; i < 12; i++) {
		free(gm->shop_inventory->items[i]->name);
		if (gm->shop_inventory->items[i]->sfname != NULL)
			sfText_destroy(gm->shop_inventory->items[i]->sfname);
	}
	free(gm->shop_inventory);
}

void destroy(game_t *gm, gui_t **guis)
{
	for (int i = 0; i < gm->map->head.height; i++) {
		free(gm->map->map[i]);
	}
	free(gm->map->map);
	free(gm->map);
	destroy_character(gm);
	for (int i = 0; guis[i] != NULL; i++) {
		destroy_gui(guis[i]);
	}
	for (int i = 0; gm->multiple_guis[i] != NULL; i++)
		destroy_multiple_gui(gm->multiple_guis[i]);
	destroy_selector(gm->pocket_selector);
	sfRenderWindow_destroy(gm->wd);
	free(gm);
}

void destroy_entity(entity_t *self)
{
	for (int i = 0; self->sprite[i]; i++)
		sfSprite_destroy(self->sprite[i]);
	free(self);
}

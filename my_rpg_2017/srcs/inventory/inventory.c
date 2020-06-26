/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** all about inventory
*/

#include "my_rpg.h"

sfText *create_txt(sfVector2f pos, char *name, int size)
{
	sfFont *font = sfFont_createFromFile("./res/font/Text_fint.ttf");
	sfText *new = sfText_create();

	sfText_setString(new, name);
	sfText_setFont(new, font);
	sfText_setCharacterSize(new, size);
	sfText_setPosition(new, pos);
	sfText_setColor(new, sfBlack);
	return (new);
}

static void conditional_display(game_t *gm, int i)
{
	if (gm->stuff[gm->pocket_selector->idx]->items[i]->stock != 0) {
		sfRenderWindow_drawText(gm->wd,
			gm->stuff[gm->pocket_selector->idx]->items[i]->sfname,
			 NULL);
	}
	sfRenderWindow_drawRectangleShape(gm->wd,
	gm->stuff[gm->pocket_selector->idx]->selector->shape, NULL);
}

static void display_txt(game_t *gm)
{
	for (int i = 0; i < 13; i++)
		conditional_display(gm, i);
}

inventory_t *create_inventory(sfTexture *texture)
{
	sfIntRect rect = {890, 2210, 380, 45};
	sfVector2f size = {380, 50};
	sfRectangleShape *shape = sfRectangleShape_create();
	inventory_t *stuff = malloc(sizeof(inventory_t));

	if (stuff == NULL)
		return (NULL);
	for (int i = 0; i < 13; i++) {
		stuff->items[i] = malloc(sizeof(item_t));
		if (stuff->items[i] == NULL)
			return (NULL);
		stuff->items[i]->name = NULL;
		stuff->items[i]->stock = 0;
		stuff->items[i]->price = 0;
		stuff->items[i]->sfname = NULL;
	}
	stuff->status = 0;
	sfRectangleShape_setTexture(shape, texture, sfFalse);
	sfRectangleShape_setTextureRect(shape, rect);
	sfRectangleShape_setSize(shape, size);
	stuff->selector = create_item_selector(shape);
	return (stuff);
}

void display_inventory(game_t *gm)
{
	if (gm->stuff[0]->status == 1 && actual_scene == -1) {
		sfRenderWindow_drawRectangleShape(gm->wd,
					gm->multiple_guis[0]->background, NULL);
		for (int i = 0; gm->multiple_guis[0]->sub_gui[i] != NULL; i++) {
			sfRenderWindow_drawRectangleShape(gm->wd,
			gm->multiple_guis[0]->sub_gui[i]->interface, NULL);
		}
		sfRenderWindow_drawRectangleShape(gm->wd,
			gm->pocket_selector->shape, NULL);
		display_txt(gm);
	}
}

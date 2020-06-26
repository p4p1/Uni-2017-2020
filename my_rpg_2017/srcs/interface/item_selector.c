/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** item selector
*/

#include "my_rpg.h"

int move_next_item(inventory_t *pocket, float dir)
{
	int new_idx = 0;
	sfVector2f pos =
	sfText_getPosition(pocket->items[pocket->selector->idx]->sfname);

	if (pos.y == 50 && dir == -60.0)
		return (0);
	pos.y += dir;
	pos.x -= 20.0;
	for (; pocket->items[new_idx]->sfname != NULL && sfText_getPosition(
		pocket->items[new_idx]->sfname).y != pos.y; new_idx++);
	pocket->selector->idx = new_idx;
	pos.y -= 10.0;
	sfRectangleShape_setPosition(pocket->selector->shape, pos);
	return (0);
}

void item_selector_event(inventory_t *pocket, game_t *gm)
{
	if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue &&
	sfKeyboard_isKeyPressed(sfKeyUp) == sfFalse) {
		if (my_strcmp(pocket->items[pocket->selector->idx]->name,
			"Fermer") != 0)
			move_next_item(pocket, 60.0);
	}
	if (sfKeyboard_isKeyPressed(sfKeyUp) &&
	sfKeyboard_isKeyPressed(sfKeyDown) == sfFalse) {
		move_next_item(pocket, -60.0);
	}
}

void destroy_item_selector(item_selector_t *selector)
{
	sfRectangleShape_destroy(selector->shape);
	free(selector);
}

item_selector_t *create_item_selector(sfRectangleShape *shape)
{
	item_selector_t *selector = malloc(sizeof(*selector));

	if (selector == NULL)
		return (NULL);
	selector->idx = 12;
	selector->shape = shape;
	return (selector);
}

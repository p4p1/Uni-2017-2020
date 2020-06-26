/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Functions about selector
*/

#include "my_rpg.h"

static void next_selection(game_t *gm, float dir)
{
	sfVector2f gap = gm->pocket_selector->gap;

	if ((gm->pocket_selector->idx == 0 && dir == -1) ||
	(gm->pocket_selector->idx == 7 && dir == 1))
		return;
	gm->pocket_selector->idx += dir;
	gap.x *= dir;
	gap.y *= dir;
	sfRectangleShape_move(gm->pocket_selector->shape, gap);
}

void select_event(pocket_selector_t *selector, game_t *gm)
{
	if (sfKeyboard_isKeyPressed(sfKeyRight) &&
	sfKeyboard_isKeyPressed(sfKeyLeft) == sfFalse)
		next_selection(gm, 1.0);
	if (sfKeyboard_isKeyPressed(sfKeyLeft) &&
	sfKeyboard_isKeyPressed(sfKeyRight) == sfFalse)
		next_selection(gm, -1.0);
}

void destroy_selector(pocket_selector_t *selector)
{
	sfRectangleShape_destroy(selector->shape);
	free(selector);
}

pocket_selector_t *create_selector(sfRectangleShape *shape,
		sfVector2f *base_pos, sfVector2f gap)
{
	pocket_selector_t *new_selector = malloc(sizeof(*new_selector));
	sfVector2f size;
	sfIntRect rect = sfRectangleShape_getTextureRect(shape);

	if (new_selector == NULL)
		return (NULL);
	size.x = rect.width + 10.0;
	size.y = rect.height + 10.0;
	if (new_selector == NULL)
		return (NULL);
	new_selector->shape = shape;
	sfRectangleShape_setPosition(new_selector->shape, *base_pos);
	sfRectangleShape_setSize(new_selector->shape, size);
	new_selector->base_pos = base_pos;
	new_selector->gap = gap;
	new_selector->idx = 0;
	return (new_selector);
}

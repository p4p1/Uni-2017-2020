/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** handle bar for health or xp
*/

#include "my_rpg.h"

void update_bar(bar_t *bar, float new_value, float max_value)
{
	sfVector2f new_size = sfRectangleShape_getSize(bar->shape);

	bar->percentage = (new_value / max_value);
	new_size.x = bar->size->x * bar->percentage;
	sfRectangleShape_setSize(bar->shape, new_size);
}

void bar_destroy(bar_t *bar)
{
	free(bar->size);
	sfClock_destroy(bar->clock);
	sfRectangleShape_destroy(bar->shape);
	free(bar);
}

bar_t *bar_create(sfVector2f *pos, sfVector2f *size, sfTexture *texture,
		sfIntRect *rect)
{
	bar_t *bar = malloc(sizeof(*bar));
	sfRectangleShape *shape = sfRectangleShape_create();

	if (bar == NULL || shape == NULL)
		return (NULL);
	sfRectangleShape_setTexture(shape, texture, sfFalse);
	sfRectangleShape_setTextureRect(shape, *rect);
	sfRectangleShape_setSize(shape, *size);
	sfRectangleShape_setPosition(shape, *pos);
	bar->rect = *rect;
	bar->shape = shape;
	bar->percentage = 100;
	bar->clock = sfClock_create();
	bar->size = size;
	return (bar);
}

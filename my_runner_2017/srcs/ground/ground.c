/*
** EPITECH PROJECT, 2017
** ground.c
** File description:
** <..>
*/

#include "my_runner.h"

static sfIntRect *create_size(int type)
{
	sfIntRect	*size = (sfIntRect *)malloc(sizeof(sfIntRect));

	if (size == NULL)
		return (NULL);
	size->top = 323;
	if (type == TOP_PIPE)
		size->left = 53;
	if (type == BOTTOM_PIPE)
		size->left = 84;
	size->height = 160;
	size->width = 30;
	return (size);
}

static void set_variables(tile_t *tl)
{
	tl->ch = 'T';
	tl->dy = 0;
	tl->frame = 1;
	tl->actual_frame = 0;
	tl->animate = &animate_sprite_fp;
	tl->move = &moving_sprite_fp;
}

tile_t *create_tile(int x_pos, int y_pos, int type)
{
	tile_t		*tl = (tile_t *)malloc(sizeof(tile_t));
	sfIntRect	*size = create_size(type);
	sfTexture	*tx;
	sfVector2f	sz;

	if (size == NULL || tl == NULL)
		return (NULL);
	set_variables(tl);
	tl->pos.x = x_pos;
	tl->pos.y = y_pos;
	tl->sprite = (sfSprite **)malloc(sizeof(sfSprite *) * 1);
	if (tl->sprite == NULL)
		return (NULL);
	sz.x = 50 / 15;
	sz.y = 50 / 15;
	tx = sfTexture_createFromFile("res/sprite.png", size);
	tl->sprite[0] = sfSprite_create();
	sfSprite_setTexture(tl->sprite[0], tx, sfTrue);
	sfSprite_setScale(tl->sprite[0], sz);
	return (tl);
}

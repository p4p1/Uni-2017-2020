/*
** EPITECH PROJECT, 2017
** title.c
** File description:
** <..>
*/

#include "my_runner.h"

static sfIntRect *create_size(void)
{
	sfIntRect	*size = (sfIntRect *)malloc(sizeof(sfIntRect));

	if (size == NULL)
		return (NULL);
	size->top = 57;
	size->left = 393;
	size->height = 30;
	size->width = 99;
	return (size);
}

static void set_variables(button_t *bt, int x, int y)
{
	bt->ch = 'O';
	bt->pos.x = x;
	bt->pos.y = y;
	bt->dy = 0;
	bt->frame = 1;
	bt->actual_frame = 0;
	bt->animate = &animate_sprite_fp;
	bt->move = &moving_sprite_fp;
	bt->size.width = 57;
	bt->size.height = 34;
}

title_t *create_death_title(int x, int y)
{
	button_t	*bt = (button_t *)malloc(sizeof(button_t));
	sfIntRect	*size = create_size();
	sfVector2f	sz;
	sfTexture	*tx;

	if (size == NULL || bt == NULL)
		return (NULL);
	set_variables(bt, x, y);
	bt->sprite = (sfSprite **)malloc(sizeof(sfSprite *) * 2);
	if (bt->sprite == NULL)
		return (NULL);
	sz.x = 50 / 15;
	sz.y = 50 / 15;
	tx = sfTexture_createFromFile("res/sprite.png", size);
	bt->sprite[0] = sfSprite_create();
	sfSprite_setTexture(bt->sprite[0], tx, sfTrue);
	sfSprite_setScale(bt->sprite[0], sz);
	return (bt);
}

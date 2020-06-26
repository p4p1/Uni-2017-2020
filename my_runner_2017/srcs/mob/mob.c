/*
** EPITECH PROJECT, 2017
** player.c
** File description:
** <..>
*/

#include "my_runner.h"

static sfIntRect *create_size(void)
{
	sfIntRect	*size = (sfIntRect *)malloc(sizeof(sfIntRect));

	if (size == NULL)
		return (NULL);
	size->top = 378;
	size->left = 115;
	size->height = 20;
	size->width = 20;
	return (size);
}

static void set_variables(player_t *p1, int x, int y)
{
	p1->ch = 'M';
	p1->pos.x = x;
	p1->pos.y = y;
	p1->dy = 0;
	p1->frame = PLAYER_FRAMES;
	p1->actual_frame = 0;
	p1->animate = &animate_sprite_fp;
	p1->move = &moving_sprite_fp;
	p1->size.width = 20;
	p1->size.height = 20;
}

player_t *create_mob(int x, int y)
{
	player_t	*p1 = (player_t *)malloc(sizeof(player_t));
	sfIntRect	*size = create_size();
	sfVector2f	sz;
	sfTexture	*tx;

	if (size == NULL || p1 == NULL)
		return (NULL);
	set_variables(p1, x, y);
	p1->sprite = (sfSprite **)malloc(sizeof(sfSprite *) * PLAYER_FRAMES);
	if (p1->sprite == NULL)
		return (NULL);
	sz.x = 50 / 15;
	sz.y = 50 / 15;
	for (int i = 0; i < PLAYER_FRAMES; i++) {
		tx = sfTexture_createFromFile("res/sprite.png", size);
		p1->sprite[i] = sfSprite_create();
		sfSprite_setTexture(p1->sprite[i], tx, sfTrue);
		sfSprite_setScale(p1->sprite[i], sz);
		size->top += 26;
	}
	return (p1);
}

/*
** EPITECH PROJECT, 2017
** background.c
** File description:
** <..>
*/

#include "my_runner.h"

static void set_variables(tile_t *tl)
{
	tl->ch = 'B';
	tl->dy = 0;
	tl->frame = 1;
	tl->actual_frame = 0;
	tl->animate = &animate_sprite_fp;
	tl->move = &moving_sprite_fp;
}

background_t *create_background(int x_pos, int y_pos, int type)
{
	background_t	*tl = (background_t *)malloc(sizeof(background_t));
	sfTexture	*tx;

	if (tl == NULL)
		return (NULL);
	set_variables(tl);
	tl->pos.x = x_pos;
	tl->pos.y = y_pos;
	tl->sprite = (sfSprite **)malloc(sizeof(sfSprite *) * 1);
	if (tl->sprite == NULL)
		return (NULL);
	if (type == SKY)
		tx = sfTexture_createFromFile("res/bg.png", NULL);
	else if (type == GRASS)
		tx = sfTexture_createFromFile("res/bg3.png", NULL);
	else
		tx = sfTexture_createFromFile("res/bg2.png", NULL);
	tl->sprite[0] = sfSprite_create();
	sfSprite_setTexture(tl->sprite[0], tx, sfTrue);
	return (tl);
}

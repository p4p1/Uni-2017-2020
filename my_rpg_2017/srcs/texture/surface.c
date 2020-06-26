/*
** EPITECH PROJECT, 2017
** surface.c
** File description:
** <..>
*/

#include "my_rpg.h"

static int draw_fp(entity_t *self, sfRenderWindow *win)
{
	sfSprite_setPosition(self->sprite[0], self->pos);
	sfRenderWindow_drawSprite(win, self->sprite[0], NULL);
	return (0);
}

static int move_fp(entity_t *self, int x, int y)
{
	self->pos.x += x;
	self->pos.y += y;
	return (0);
}

static int collide_fp(entity_t *self, int x, int y)
{
	(void)self;
	(void)x;
	(void)y;
	return (0);
}

static entity_t *set_texture(entity_t *self, enum entity_type type)
{
	sfTexture	*tx;

	tx = sfTexture_createFromFile("res/texture/tileset.png",
			get_size(type));
	if (tx == NULL)
		return (self);
	self->sprite[0] = sfSprite_create();
	if (self->sprite[0] == NULL)
		return (self);
	sfSprite_setTexture(self->sprite[0], tx, sfTrue);
	return (self);
}

entity_t *create_surface(int x, int y, enum entity_type type)
{
	entity_t	*self = malloc(sizeof(entity_t));

	self->type = type;
	self->pos.x = x;
	self->pos.y = y;
	self->sprite = malloc(sizeof(sfSprite *));
	if (self->sprite == NULL)
		return (self);
	self->draw = &draw_fp;
	self->move = &move_fp;
	self->collide = &collide_fp;
	self = set_texture(self, type);
	return (self);
}

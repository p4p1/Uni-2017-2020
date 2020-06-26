/*
** EPITECH PROJECT, 2017
** player.c
** File description:
** <..>
*/

#include "my_prg.h"

static int draw_fp(entity_t *self, sfRenderWindow *win)
{
	sfSprite_setPosition(self->sprite[0], self->pos);
	sfRenderWindow_drawSprite(win, self->sprite[0], NULL);
	return (0);
}

static int move_fp(entity_t *self, int x, int y)
{
	self->pos.x = x;
	self->pos.y = y;
	return (0);
}

static int collide_fp(entity_t *self, int x, int y)
{
	sfFloatRect	taille = sfSprite_getGlobalBounds(self->sprite[0]);

	if (self->pos.x <= x && self->pos.x + taille.width >= x &&
		self->pos.y <= y && self->pos.y + taille.height >= y)
		return (1);
	return (0);
}

static entity_t *set_texture(entity_t *self)
{
	sfTexture	**tx;

	tx = malloc(sizeof(sfTexture *) * 8);
	if (tx == NULL)
		return (NULL);
	for (int i = 0; i < 8; i++) {
		tx[i] = sfTexture_createFromFile("res/texture/tileset.png",
				NULL);
		if (tx[i] == NULL)
			return (NULL);
	}
	for (int i = 0; i < 8; i++) {
		self->sprite[i] = sfSprite_create();
		if (self->sprite[i] == NULL)
			return (NULL);
		sfSprite_setTexture(self->sprite[i], tx, sfTrue);
	}
	return (self);
}

entity_t *create_player(int x, int y)
{
	entity_t	*self = malloc(sizeof(entity_t));

	if (self == NULL)
		return (NULL);
	self->type = PLAYER;
	self->pos.x = x;
	self->pos.y = y;
	self->sprite = malloc(sizeof(sfSprite *) * 8);
	if (self->sprite == NULL)
		return (NULL);
	self->draw = &draw_fp;
	self->move = &move_fp;
	self->collide = &collide_fp;
	self = set_texture(self);
	return (self);
}

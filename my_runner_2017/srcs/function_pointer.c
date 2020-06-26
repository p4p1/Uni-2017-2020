/*
** EPITECH PROJECT, 2017
** function_pointer.c
** File description:
** <..>
*/

#include "my_runner.h"

static void rotate(struct __entity__ *self)
{
	float	rotate = (self->dy <= 0) ? 15.5f : -15.5f;

	for (int i = 0; i < self->frame; i++)
		sfSprite_setRotation(self->sprite[i], rotate);
}

int animate_sprite_fp(struct __entity__ *self, sfRenderWindow *win)
{
	if (self->ch == 'P') {
		rotate(self);
		self->pos.y -= self->dy;
		self->dy -= GRAVITY;
	}
	self->actual_frame++;
	if (self->actual_frame >= self->frame)
		self->actual_frame = 0;
	sfSprite_setPosition(self->sprite[self->actual_frame], self->pos);
	sfRenderWindow_drawSprite(win, self->sprite[self->actual_frame], NULL);
	return (0);
}

int moving_sprite_fp(struct __entity__ *self, int x_pos, int y_pos)
{
	if (self->ch == 'B' && self->pos.x + x_pos <= -1080)
		self->pos.x = 1080;
	self->pos.x += x_pos;
	self->pos.y += y_pos;
	return (0);
}

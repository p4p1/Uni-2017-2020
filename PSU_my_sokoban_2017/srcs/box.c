/*
** EPITECH PROJECT, 2017
** box.c
** File description:
** <..>
*/

#include "my_sokoban.h"

static void display_fp(Box_t *self)
{
	my_printf("Box\n");
	if (self != NULL) {
		my_printf("pos: %d/%d\n", self->x, self->y);
		my_printf("initial_pos: %d/%d\n", self->initial_x,
			self->initial_y);
	} else {
		my_printf("BOX IS NULL!\n");
	}
}

static void move_fp(Box_t *self, struct game *gm, int x, int y)
{
	if (self != NULL && gm->map[self->y + y][self->x + x] != '#' &&
			gm->map[self->y + y][self->x + x] != 'X') {
		if (self->in_box) {
			gm->map[self->y][self->x] = 'O';
			self->in_box = 0;
		} else {
			gm->map[self->y][self->x] = ' ';
		}
		self->x += x;
		self->y += y;
		if (gm->map[self->y][self->x] == 'O')
			self->in_box = 1;
		self->draw(self, gm);
	}
}

static void reset_fp(Box_t *self)
{
	if (self != NULL) {
		self->x = self->initial_x;
		self->y = self->initial_y;
	}
}

static void draw_fp(Box_t *self, struct game *gm)
{
	if (self != NULL) {
		gm->map[self->y][self->x] = self->ch;
	}
}

Box_t *init_box(void *ini_x, void *ini_y)
{
	Box_t	*self = (Box_t *)malloc(sizeof(Box_t));

	if (self == NULL)
		return (NULL);
	self->initial_x = *(int *)ini_x;
	self->initial_y = *(int *)ini_y;
	self->x = *(int *)ini_x;
	self->y = *(int *)ini_y;
	self->ch = 'X';
	self->in_box = 0;
	self->disp = &display_fp;
	self->move_pos = &move_fp;
	self->reset = &reset_fp;
	self->draw = &draw_fp;
	return (self);
}

/*
** EPITECH PROJECT, 2017
** player.c
** File description:
** <..>
*/

#include "my_sokoban.h"

static void display_fp(Player_t *self)
{
	my_printf("Player\n");
	if (self != NULL) {
		my_printf("pos: %d/%d\n", self->x, self->y);
		my_printf("initial_pos: %d/%d\n", self->initial_x,
				self->initial_y);
	} else {
		my_printf("PLAYER IS NULL!\n");
	}
}

static void move_fp(Player_t *self, struct game *gm, int x, int y)
{
	int	box_no = 0;

	if (self->x + x <= 0 && self->y + y <= 0)
		return;
	if (self != NULL && gm->map[self->y + y][self->x + x] == 'X')
		if ((box_no = get_box(gm, self->x + x, self->y + y)) != -1)
			gm->bx[box_no]->move_pos(gm->bx[box_no], gm, x, y);
	if (self != NULL && gm->map[self->y + y][self->x + x] != '#' &&
			gm->map[self->y + y][self->x + x] != 'X') {
		gm->map[self->y][self->x] = (self->in_box)? 'O' : ' ';
		if (gm->map[self->y + y][self->x + x] == 'O')
			self->in_box = 1;
		else
			self->in_box = 0;
		self->x += x;
		self->y += y;
		self->draw(self, gm);
	}
}

static void reset_fp(Player_t *self)
{
	if (self != NULL) {
		self->x = self->initial_x;
		self->y = self->initial_y;
	}
}

static void draw_fp(Player_t *self, struct game *gm)
{
	if (self != NULL) {
		gm->map[self->y][self->x] = self->ch;
	}
}

Player_t *init_player(void *ini_x, void *ini_y)
{
	Player_t	*self = (Player_t *)malloc(sizeof(Player_t));

	if (self == NULL)
		return (NULL);
	self->initial_x = *(int *)ini_x;
	self->initial_y = *(int *)ini_y;
	self->x = *(int *)ini_x;
	self->y = *(int *)ini_y;
	self->ch = 'P';
	self->in_box = 0;
	self->disp = &display_fp;
	self->move_pos = &move_fp;
	self->reset = &reset_fp;
	self->draw = &draw_fp;
	return (self);
}

/*
** EPITECH PROJECT, 2017
** paralax.c
** File description:
** <..>
*/

#include "my_rpg.h"

extern struct __entity__	qu[22][40];

void paralax_up(game_t *gm)
{
	int	x_pos = (int)gm->hero->pos_map.x - 20;
	int	y_pos = (int)gm->hero->pos_map.y - 11;

	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 40; j++) {
			qu[i][j].move(&qu[i][j], 0, gm->hero->speed);
		}
	}
	if (qu[21][0].pos.y > HEIGHT - 20) {
		for (int i = 0; i < 40; i++) {
			gm->map->map[y_pos + 21][x_pos + i].on_s = 0;
		}
		move_tab_up();
	}
}

void paralax_down(game_t *gm)
{
	for (int i = 0; i < 22; i++)
		for (int j = 0; j < 40; j++)
			qu[i][j].move(&qu[i][j], 0, gm->hero->speed * -1);
}

void paralax_right(game_t *gm)
{
	for (int i = 0; i < 22; i++)
		for (int j = 0; j < 40; j++)
			qu[i][j].move(&qu[i][j], gm->hero->speed * -1, 0);
}

void paralax_left(game_t *gm)
{
	for (int i = 0; i < 22; i++)
		for (int j = 0; j < 40; j++)
			qu[i][j].move(&qu[i][j], gm->hero->speed, 0);
}

/*
** EPITECH PROJECT, 2017
** game.c
** File description:
** <..>
*/

#include "my_runner.h"

static int even_handler(struct game *gm)
{
	sfEvent	event;

	while (sfRenderWindow_pollEvent(gm->win, &event)) {
		if (event.type == sfEvtKeyPressed &&
				event.key.code == sfKeySpace) {
			gm->p1->dy = 20.0f;
			sfSound_play(gm->sound);
		}
		if (event.type == sfEvtClosed)
			return (-1);
	}
	return (0);
}

static int colision_detection(struct game *gm)
{
	int		no = 0;

	for (int i = 0; i < gm->set->no_tile; i++) {
		no += colision(gm->p1, gm->ground[i]);
		if (gm->p1->pos.x == gm->ground[i]->pos.x) {
			gm->score++;
		}
	}
	for (int i = 0; i < gm->set->no_mob; i++) {
		no += colision(gm->p1, gm->mob[i]);
	}
	if (gm->p1->pos.x > WIDTH || gm->p1->pos.y > HEIGHT ||
			gm->p1->pos.x < 0 || gm->p1->pos.y < 0)
		return (1);
	return (no);
}

static void replace_ground_infin(struct game *gm)
{
	int	x_pos = 0;
	int	y_pos = 0;
	int	type = TOP_PIPE;
	int	i = 0;

	for (i = 0; i < gm->set->no_tile; i++) {
		type = (gm->ground[i]->pos.y < 0) ? TOP_PIPE : BOTTOM_PIPE;
		y_pos = (type == TOP_PIPE) ? rand() % 300 + 200 : rand() %
			500 + 400;
		y_pos *= (type == TOP_PIPE) ? -1 : 1;
		x_pos = 1000;
		if (gm->ground[i]->pos.x < -100) {
			gm->ground[i] = create_tile(x_pos, y_pos, type);
		}
	}
}

static void draw_sprite(struct game *gm)
{
	int	i = 0;

	for (i = 0; i < (BACKGROUND_NO / 2); i++) {
		gm->bg[i]->animate(gm->bg[i], gm->win);
		gm->bg[i]->move(gm->bg[i], -1 * (i + 1), 0);
		gm->bg[i + (BACKGROUND_NO / 2)]->animate(gm->bg[i +
				(BACKGROUND_NO / 2)], gm->win);
		gm->bg[i + (BACKGROUND_NO / 2)]->move(gm->bg[i +
				(BACKGROUND_NO / 2)], -1 * (i + 1), 0);
	}
	gm->p1->animate(gm->p1, gm->win);
	for (i = 0; i < gm->set->no_tile; i++) {
		gm->ground[i]->animate(gm->ground[i], gm->win);
		gm->ground[i]->move(gm->ground[i], -5, 0);
	}
	for (i = 0; i < gm->set->no_mob; i++) {
		gm->mob[i]->animate(gm->mob[i], gm->win);
		gm->mob[i]->move(gm->mob[i], -10, 0);
	}
	sfRenderWindow_drawText(gm->win, gm->score_text, NULL);
}

int main_game(struct game *gm)
{
	int	quit = 0;
	int	ret = 0;
	sfVector2f	pos;

	pos.x = 0;
	pos.y = 0;
	sfText_setPosition(gm->score_text, pos);
	while (sfRenderWindow_isOpen(gm->win) && quit == 0) {
		quit = 0;
		if((ret = even_handler(gm)) < 0)
			break;
		draw_sprite(gm);
		if (gm->set->infin_mode)
			replace_ground_infin(gm);
		quit = colision_detection(gm);
		sfRenderWindow_display(gm->win);
		sfText_setString(gm->score_text, my_itoa(gm->score));
		sfSleep(gm->fps);
		sfRenderWindow_clear(gm->win, sfBlack);
	}
	return (ret);
}

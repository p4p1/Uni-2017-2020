/*
** EPITECH PROJECT, 2017
** menu.c
** File description:
** <..>
*/

#include "my_runner.h"

static int colision_detection(struct game *gm, sfEvent event)
{
	sfFloatRect	bord;
	sfFloatRect	bord2;

	bord = sfSprite_getGlobalBounds(gm->btn_start->sprite[0]);
	bord2 = sfSprite_getGlobalBounds(gm->btn_info->sprite[0]);
	if ((gm->btn_start->pos.x < event.mouseButton.x && gm->btn_start->pos.x
			+ bord.width > event.mouseButton.x) &&
			(gm->btn_start->pos.y < event.mouseButton.y &&
			gm->btn_start->pos.y + bord.height >
			event.mouseButton.y)) {
		return (1);
	}
	if ((gm->btn_info->pos.x < event.mouseButton.x && gm->btn_info->pos.x
			+ bord2.width > event.mouseButton.x) &&
			(gm->btn_info->pos.y < event.mouseButton.y &&
			gm->btn_info->pos.y + bord2.height >
			event.mouseButton.y)) {
		return (2);
	}
	return (0);
}

static int even_handler(struct game *gm)
{
	sfEvent	event;

	while (sfRenderWindow_pollEvent(gm->win, &event)) {
		if (event.type == sfEvtMouseButtonPressed) {
			return (colision_detection(gm, event));
		}
		if (event.type == sfEvtClosed)
			return (-1);
	}
	return (0);
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
	gm->btn_start->animate(gm->btn_start, gm->win);
	gm->btn_info->animate(gm->btn_info, gm->win);
	gm->title->animate(gm->title, gm->win);
}

int menu(struct game *gm)
{
	int	no = 0;

	while (sfRenderWindow_isOpen(gm->win)) {
		if((no = even_handler(gm)) != 0)
			break;
		draw_sprite(gm);
		sfRenderWindow_display(gm->win);
		sfSleep(gm->fps);
		sfRenderWindow_clear(gm->win, sfBlack);
	}
	return (no);
}

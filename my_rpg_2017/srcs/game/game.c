/*
** EPITECH PROJECT, 2017
** game.c
** File description:
** <..>
*/

#include <stdio.h>
#include "my_rpg.h"

static void inventory_event(game_t *gm)
{
	select_event(gm->pocket_selector, gm);
	item_selector_event(gm->stuff[gm->pocket_selector->idx], gm);
}

static int event_handler(game_t *gm, character_t *hero, object_t *obj)
{
	int	no = -1;

	hero->speed = 1;
	while (sfRenderWindow_pollEvent(gm->wd, &gm->event)) {
		if (gm->event.type == sfEvtClosed)
			sfRenderWindow_close(gm->wd);
		if (gm->stuff[0]->status == 0)
			player_movement(hero, gm, obj);
		if (gm->stuff[0]->status == 1)
			inventory_event(gm);
		if (gm->event.type == sfEvtKeyPressed &&
		sfKeyboard_isKeyPressed(sfKeyA))
			actual_scene = 2;
		if (gm->event.type == sfEvtKeyPressed &&
		sfKeyboard_isKeyPressed(sfKeyEscape)) {
			gm->stuff[0]->status = 0;
			actual_scene = 1;
		}
		fill_inventory(gm, gm->shop_inventory->items[0]);
	}
	return (no);
}

int game(game_t *gm, gui_t **gui)
{
	int	no = 1;

	while (sfRenderWindow_isOpen(gm->wd)) {
		if (actual_scene == 2)
			start_fight(gui, gm);
		if (actual_scene == -1)
			event_handler(gm, gm->hero, gm->new_obj);
		if (actual_scene == 4)
			stat_menu(gui, gm, gm->hero->pokemon[0]);
		if (actual_scene == -1 || actual_scene == 1) {
			display_inventory(gm);
			disp_map(gm);
		}
		if (actual_scene != -1)
			display_menu(gui, gm);
		sfRenderWindow_display(gm->wd);
		sfSleep(gm->tm);
		sfRenderWindow_clear(gm->wd, sfBlack);
	}
	return (no);
}

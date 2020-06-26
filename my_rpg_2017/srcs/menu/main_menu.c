/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main menu scene
*/

#include <stdlib.h>
#include "my_rpg.h"

void menu_event(gui_t **guis, game_t *gm)
{
	sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(gm->wd);

	while (sfRenderWindow_pollEvent(gm->wd, &gm->event)) {
		button_event(guis[actual_scene]->buttons, &mouse_pos);
		if (gm->event.type == sfEvtClosed)
			sfRenderWindow_close(gm->wd);
		if (actual_scene == 1 && gm->event.type == sfEvtKeyPressed &&
		sfKeyboard_isKeyPressed(sfKeyEscape)) {
			actual_scene = -1;
			break;
		}
	}
}

void display_menu(gui_t **guis, game_t *gm)
{
	int scene = actual_scene;

	sfRenderWindow_drawRectangleShape(gm->wd,
					guis[actual_scene]->interface, NULL);
	for (int i = 0; guis[actual_scene]->buttons[i] != NULL; i++) {
		display_button(guis[actual_scene]->buttons[i], gm->wd);
		if (guis[actual_scene]->buttons[i]->state == CLICKED)
			guis[actual_scene]->buttons[i]->
				callback(guis[actual_scene]->buttons[i], gm);
		if (actual_scene != scene)
			return;
	}
	menu_event(guis, gm);
}

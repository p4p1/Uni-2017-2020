/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** display and handle multi_gui menus
*/

#include "my_rpg"

void disp_multi_gui(game_t *gm, multiple_gui_t *gui)
{
	sfRenderWindow_drawRectangleShape(gm->wd, gui->background);
	for (int i = 0; gui->sub_gui[i] != NULL; i++) {
		display_gui(gui->sub_gui[i], gm->wd);
	}
}

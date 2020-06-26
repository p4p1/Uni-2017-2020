/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** button functions for pause menu
*/

#include <stdlib.h>
#include "my_rpg.h"

void pokemon_button(button_t *button, game_t *gm)
{
	(void)gm;
	actual_scene = 3;
	button->state = IDLE;
	button_change_state(CLICKED, button);
}

void bag_button(button_t *button, game_t *gm)
{
	if (actual_scene == 1)
		actual_scene = -1;
	gm->stuff[0]->status = 1;
	button->state = IDLE;
	button_change_state(CLICKED, button);
}

void save_button(button_t *button, game_t *gm)
{
	(void)button;
	(void)gm;
}

void option_button(button_t *button, game_t *gm)
{
	(void)button;
	(void)gm;
}

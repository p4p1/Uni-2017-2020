/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** button for pokemon menu
*/

#include "my_rpg.h"

void button_stat_pokemon(button_t *button, game_t *game)
{
	(void)game;
	actual_scene = 4;
	button->state = IDLE;
	button_change_state(CLICKED, button);
}

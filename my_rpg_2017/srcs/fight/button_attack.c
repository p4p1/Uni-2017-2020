/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** button attack in fight
*/

#include "my_rpg.h"

void attack_button(button_t *button, game_t *gm)
{
	actual_scene = 5;
	button->state = IDLE;
	button_change_state(CLICKED, button);
}

void annuler_button(button_t *button, game_t *gm)
{
	actual_scene = 2;
	button->state = IDLE;
	button_change_state(CLICKED, button);
}

void fuite_button(button_t *button, game_t *gm)
{
	actual_scene = -1;
	button->state = IDLE;
	button_change_state(CLICKED, button);
}

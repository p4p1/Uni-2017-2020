/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** callback for menus buttons
*/

#include "my_rpg.h"
#include "my_printf.h"

void play(button_t *button, game_t *gm)
{
	(void) gm;
	(void) button;
	actual_scene = -1;
	button->state = IDLE;
	button_change_state(CLICKED, button);
}

void quit(button_t *button, game_t *gm)
{
	(void) button;
	sfRenderWindow_close(gm->wd);
}

void attack(button_t *button, game_t *gm)
{
	(void) gm;
	(void) button;
}

void quit_to_start(button_t *button, game_t *gm)
{
	(void) gm;
	(void) button;
	actual_scene = 0;
	button->state = IDLE;
	button_change_state(CLICKED, button);
}

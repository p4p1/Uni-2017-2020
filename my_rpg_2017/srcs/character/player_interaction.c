/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** all of the character interaction with the game
*/

#include "my_rpg.h"

void player_movement(character_t *hero, game_t *gm, object_t *new_object)
{
	speed_variation(hero, gm);
	if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue)
		up_movement(hero, new_object);
	if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
		down_movement(hero, new_object);
	if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue)
		right_movement(hero, new_object);
	if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
		left_movement(hero, new_object);
}

void using_shop(game_t *gm)
{
	(void)gm;
}

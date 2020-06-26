/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** movement and speed variation of character
*/

#include "my_rpg.h"

void left_movement(character_t *hero, object_t *new_object)
{
	sfVector2f left_move = {-3.0 * hero->speed, 0.0};

	if (hero->speed == 2)
		new_object->actual_state.top = 250;
	else
		new_object->actual_state.top = 50;
	hero->pos_map.x += left_move.x;
	animate(new_object, hero);
}

void right_movement(character_t *hero, object_t *new_object)
{
	sfVector2f right_move = {3.0 * hero->speed, 0.0};

	if (hero->speed == 2)
		new_object->actual_state.top = 300;
	else
		new_object->actual_state.top = 100;
	hero->pos_map.x += right_move.x;
	animate(new_object, hero);
}

void up_movement(character_t *hero, object_t *new_object)
{
	sfVector2f up_move = {0.0, -3.0 * hero->speed};

	if (hero->speed == 2)
		new_object->actual_state.top = 350;
	else
		new_object->actual_state.top = 150;
	hero->pos_map.y += up_move.y;
	animate(new_object, hero);
}

void down_movement(character_t *hero, object_t *new_object)
{
	sfVector2f down_move = {0.0, 3.0 * hero->speed};

	if (hero->speed == 2)
		new_object->actual_state.top = 200;
	else
		new_object->actual_state.top = 0;
	hero->pos_map.y += down_move.y;
	animate(new_object, hero);
}

void speed_variation(character_t *hero, game_t *gm)
{
	if (sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue)
		hero->speed = 2;
	else
		hero->speed = 1;
}

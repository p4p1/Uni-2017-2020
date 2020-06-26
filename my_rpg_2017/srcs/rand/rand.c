/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** all random function
*/

#include "my_rpg.h"

int find_savage_pokemon(void)
{
	int combat = rand() % 13;

	return (combat);
}

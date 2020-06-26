/*
** EPITECH PROJECT, 2017
** get_size.c
** File description:
** <..>
*/

#include "my_rpg.h"

sfIntRect *get_size(enum entity_type type)
{
	sfIntRect	*(*tab[])(void) = { &tree_1,  &tree_2, &tree_3,
		&tree_4, &tree_snow_1, &tree_snow_2, &grass_1, &dirt_1,
		&dirt_2, &dirt_3, &poke_center, &poke_market };

	return (tab[type]());
}

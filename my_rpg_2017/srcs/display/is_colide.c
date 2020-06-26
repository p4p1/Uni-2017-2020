/*
** EPITECH PROJECT, 2017
** is_colide.c
** File description:
** <..>
*/

#include "my_rpg.h"

static int is_colide(enum entity_type type)
{
	static enum entity_type	tab[10] = {TREE1, TREE2, TREE3, TREE4,
		TREESNOW1, TREESNOW2, POKECENTER, POKEMARKET, PLAYER, NPC};

	for (int i = 0; i < 10; i++)
		if (tab[i] == type)
			return (1);
	return (0);
}

static int is_ground(enum entity_type type)
{
	static enum entity_type	tab[4] = {GRASS1, DIRT1, DIRT2, DIRT3};

	for (int i = 0; i < 4; i++)
		if (tab[i] == type)
			return (1);
	return (0);
}

int can_draw(map_t self)
{
	if (is_colide(self.tile.type) && !self.on_s)
		return (COLIDABLE);
	else if (is_ground(self.tile.type) && !self.on_s)
		return (GROUND);
	else
		return (-1);
}

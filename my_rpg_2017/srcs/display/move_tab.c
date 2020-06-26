/*
** EPITECH PROJECT, 2017
** move_tab.c
** File description:
** <..>
*/

#include "my_rpg.h"

extern struct __entity__	*qu[22][40];

void move_tab_up(void)
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			qu[i + 1][j] = qu[i][j];
		}
	}
}

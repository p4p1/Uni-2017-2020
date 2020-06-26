/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** ..
*/

#include "connect4.h"

static void first_and_last(struct game *gm)
{
	for (int j = 0; j != gm->width + 2; j++)
		my_putchar('+');
	my_putchar('\n');	
}

void display_map(struct game *gm)
{
	first_and_last(gm);
	for (int i = 0; gm->map[i] != NULL; i++)
		my_printf("|%s|\n", gm->map[i]);
	first_and_last(gm);
}

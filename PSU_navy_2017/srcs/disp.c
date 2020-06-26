/*
** EPITECH PROJECT, 2017
** disp.c
** File description:
** <..>
*/

#include "navy.h"

void disp_map(char **map)
{
	my_printf(" |A B C D E F G H\n");
	my_printf("-+---------------\n");
	for (int i = 0; map[i]; i++)
		my_printf("%d|%s\n", i + 1, map[i]);
	my_putchar('\n');
}

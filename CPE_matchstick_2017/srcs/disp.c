/*
** EPITECH PROJECT, 2017
** disp.c
** File description:
** ..>
*/

#include "matchstick.h"

static void padding(int max, int len)
{
	int	i = 0;

	for (i = 0; i < ((max / 2) - (len / 2)); i++)
		my_putchar(' ');
}

void display_map(char **map, int size)
{
	int	i = 0;

	for (i = 0; i < size + 2; i++)
		my_putchar('*');
	my_putchar('\n');
	for (i = 0; map[i]; i++) {
		my_putchar('*');
		padding(size, my_strlen(map[i]));
		my_printf("%s", map[i]);
		padding(size, my_strlen(map[i]));
		my_putstr("*\n");
	}
	for (i = 0; i < size + 2; i++)
		my_putchar('*');
	my_putchar('\n');
}

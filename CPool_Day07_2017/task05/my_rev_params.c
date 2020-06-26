/*
** EPITECH PROJECT, 2017
** my_rev_params.c
** File description:
** print all params in reverse order
*/

#include "../include/my.h"

void my_rev_params(int ac, char **av)
{
	int	inc = ac -1;

	while (inc >= 0) {
		my_putstr(*(av+inc--));
		my_putchar('\n');
	}
}

/*
** EPITECH PROJECT, 2017
** my_print_params.c
** File description:
** print all the paramaters of the program
*/

#include "../include/my.h"

void my_print_params(int ac, char **av)
{
	int	inc = 0;

	while (inc < ac) {
		my_putstr(*(av+inc++));
		my_putchar('\n');
	}
}

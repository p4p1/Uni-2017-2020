/*
** EPITECH PROJECT, 2017
** debug.c
** File description:
** main file for debugging
*/

#include "hidenp.h"

int debug_main(int ac, char **av)
{
	int	i = 0;
	int	j = 0;

	if (ac != 3) {
		my_puts_err("Usage:\t");
		my_puts_err(av[0]);
		my_puts_err(" needle haystack\n");
		return (84);
	}
	for (i = 0; av[2][i] != '\0'; i++)
		if (av[1][j] != '\0' && av[1][j] == av[2][i])
			j++;
	if (j == my_strlen(av[1]))
		my_puts("1");
	else
		my_puts("0");
	return (0);
}

/*
** EPITECH PROJECT, 2017
** error.c
** File description:
** <..>
*/

#include "fractals.h"

static int is_num(char *str)
{
	for (int i = 0; str[i]; i++)
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int check_params(int ac, char **av)
{
	if (ac != 4)
		return (-1);
	if (!is_num(av[1]))
		return (-1);
	for (int i = 0; av[2][i]; i++)
		if (av[2][i] != '#' && av[2][i] != '.' && av[2][i] != '@')
			return (-1);
	for (int i = 0; av[3][i]; i++)
		if (av[3][i] != '.' && av[3][i] != '@')
			return (-1);
	return (0);
}

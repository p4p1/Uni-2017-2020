/*
** EPITECH PROJECT, 2017
** arguments.c
** File description:
** get the number of arguments
*/

#include "include/rush2.h"

int get_args(int size, char arguments[size], char **av)
{
	int	first_arg = 2;
	int	i = 0;

	if (size < 3)
		return (-1);
	for (first_arg = 2; first_arg < size; first_arg++) {
		arguments[i] = av[first_arg][0];
		i += 1;
	}
	arguments[i] = '\0';
	return (0);
}

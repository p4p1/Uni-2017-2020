/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** <..>
*/

#include "fractals.h"

char *fractals(int i, char *chain1, char *chain2)
{
	char *buff = my_strdup(chain1);

	for (int j = 1; j < i; j++) {
		buff = my_fract_replace(buff, chain1, chain2);
	}
	return (buff);
}

int main(int ac, char **av)
{
	if (check_params(ac, av) < 0)
		return (84);
	if (my_atoi(av[1]) == 0) {
		write(1, "#\n", 2);
	} else {
		my_printf("%s\n", my_return_replace(fractals(my_atoi(av[1]),
					av[2],
					av[3])));
	}
	return (0);
}

/*
** EPITECH PROJECT, 2017
** tests_debug.c
** File description:
** the debug function program
*/

#include "tests.h"

char **debug(int ac, char **av)
{
	bsq_class	*bsq;
	int		fd = 0;

	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	if ((bsq = init_bsq(fd)) == NULL)
		return (NULL);
	if (algo(bsq) > 0)
		return (NULL);
	set_solution(bsq);
	return (bsq->map);
}

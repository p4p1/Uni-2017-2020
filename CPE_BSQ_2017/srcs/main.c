/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main file for bsq
*/

#include "bsq.h"

static int disp_map(char **map, int size, int width)
{
	int	i = 0;

	if (map == NULL)
		return (0);
	for (i = 0; i < size; i++) {
		write(1, map[i], width);
	}
	return (0);
}

int main(int ac, char **av)
{
	bsq_class	*bsq;
	int		fd = 0;

	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (84);
	if ((bsq = init_bsq(fd)) == NULL)
		return (84);
	if (algo(bsq) > 0)
		return (84);
	set_solution(bsq);
	disp_map(bsq->map, bsq->size.height, bsq->size.width);
	return (0);
}

/*
** EPITECH PROJECT, 2017
** algo.c
** File description:
** the bsq algorithm
*/

#include "bsq.h"

int algo(bsq_class *bsq)
{
	int	i = 0;

	for (i = 0; i < bsq->size.height; i++) {
		bsq->map[i] = bsq->get_line(bsq);
		if (bsq->map[i] == NULL)
			return (84);
		bsq->scan_line(bsq);
	}
	return (0);
}

/*
** EPITECH PROJECT, 2017
** sol.c
** File description:
** <..>
*/

#include "bsq.h"

void set_solution(bsq_class *bsq)
{
	int	sol = bsq->sol[bsq->bigest_pos.y][bsq->bigest_pos.x];
	int	i = 0;
	int	j = 0;

	for (j = sol; j > 0; j--) {
		for (i = sol; i > 0; i--) {
			bsq->map[bsq->bigest_pos.y - j + 1]
				[bsq->bigest_pos.x - i + 1] = 'x';
		}
	}
}

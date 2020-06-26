/*
** EPITECH PROJECT, 2017
** my_compute_factorial_it
** File description:
** compute the factorial it function
*/

#include "my.h"

int my_compute_factorial_it(int nb)
{
	int	sol = 1;
	int	i = 0;

	if (nb == 0)
		return (1);
	while (i < nb)
		sol *= ++i;
	return (sol);
}

/*
** EPITECH PROJECT, 2017
** my_sort_params.c
** File description:
** sort in ascii order the params
*/

#include "../include/my.h"

void is_smaller(char **tab, int ii)
{
	char	*tmp;

	if (tab[ii][0] > tab[ii+1][0]) {
		tmp = tab[ii];
		tab[ii] = tab[ii+1];
		tab[ii+1] = tmp;
	}
}

void my_sort_char_array(char **tab, int size)
{
	int	i = 0;
	int	ii;

	while (i < (size - 1)) {
		ii = 0;
		while (ii < (size - i - 1)) {
			is_smaller(tab, ii);
			++ii;
		}
		++i;
	}
}

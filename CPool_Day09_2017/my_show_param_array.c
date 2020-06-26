/*
** EPITECH PROJECT, 2017
** my_show_param_array
** File description:
** display all of the param
*/

#include "include/my.h"

void my_putchar(char c);

int my_show_param_array(struct info_param const *par)
{
	int	i = -1;
	int	x = 0;

	if (par == 0)
		return (0);
	while (par[++i].str != 0) {
		my_put_nbr(par[i].length);
		my_putstr(par[i].str);
		my_putstr(par[i].copy);
		for (x = 0; par[i].word_array[x] != 0; x++) {
			my_putstr(par[i].word_array[x]);
		}
	}
	return (0);
}


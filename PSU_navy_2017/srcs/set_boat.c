/*
** EPITECH PROJECT, 2017
** set_boat.c
** File description:
** <..>
*/

#include "navy.h"

static int place_boat(struct boat bt, char **tab, int i, int *size)
{
	for (int j = bt.posy_ini; j <= bt.posy_final; j++) {
		if (tab[j][i] != '.')
			return (-1);
		tab[j][i] = bt.size + 48;
		*size += 1;
	}
	return (0);
}

int set_boat(struct boat bt, char **tab)
{
	int	size = 0;

	for (int i = bt.posx_ini * 2; i <= (bt.posx_final * 2); i += 2) {
		if (place_boat(bt, tab, i, &size) == -1)
			return (-1);
	}
	if (size != bt.size) {
		return (-1);
	}
	return (0);

}

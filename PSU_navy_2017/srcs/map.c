/*
** EPITECH PROJECT, 2017
** map.c
** File description:
** <..>
*/

#include "navy.h"

void place_map(char **map, int x, int y, char ch)
{
	map[y][x] = ch;
}

int is_hit(char **map, int x, int y)
{
	if (map[y][x * 2] == ' ' || map[y][x * 2] == '.')
		return (0);
	return (1);
}

void is_good(int sig)
{
	if (sig == SIGUSR1) {
		my_printf("%c%c: hit\n\n", cdat->posx + 65,
				cdat->posy + 49);
		cdat->stat = HIT;
	} else {
		my_printf("%c%c: missed\n\n", cdat->posx + 65,
				cdat->posy + 49);
		cdat->stat = WAITING;
	}
}

int is_win(char **map)
{
	int	no = 0;

	for (int i = 0; map[i]; i++) {
		for (int j = 0; map[i][j]; j++) {
			no = (map[i][j] == 'x') ? no + 1: no;
		}
	}
	if (no == 14)
		return (1);
	else
		return (0);
}

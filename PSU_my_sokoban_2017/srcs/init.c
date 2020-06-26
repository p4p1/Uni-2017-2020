/*
** EPITECH PROJECT, 2017
** init.c
** File description:
** initialization functions
*/

#include "my_sokoban.h"

static void init_ncurses(void)
{
	initscr();
	raw();
	noecho();
	cbreak();
	timeout(10);
	curs_set(0);
}

static int incorect_map(struct game *gm)
{
	int	i = 0;
	int	j = 0;
	int	no = 0;

	for (i = 0; gm->map[i]; i++) {
		for (j = 0; gm->map[i][j]; j++) {
			no = (gm->map[i][j] != 'P' && gm->map[i][j] != 'O' &&
			gm->map[i][j] != 'X' && gm->map[i][j] != '#' &&
			gm->map[i][j] != 32 && gm->map[i][j] != '\n') ? 1 : no;
		}
	}
	return (no);
}

static int init_map(struct game *gm, char **argv)
{
	int	x = 0;
	int	y = 0;

	gm->map = get_map(argv, gm);
	if (gm->map == NULL || incorect_map(gm)) {
		destroy(gm);
		return (-1);
	}
	get_player_coor(&x, &y, gm->map);
	gm->p1 = init_player((void *)&x, (void *)&y);
	return (0);
}

int init_game(char **argv, struct game *gm)
{
	unsigned int	i = 0;
	int		x = 0;
	int		y = 0;

	init_ncurses();
	if (init_map(gm, argv) < 0)
		return (-1);
	gm->bx = (Box_t **)malloc(sizeof(Box_t *) * gm->no_box);
	if (gm->p1 == NULL || gm->bx == NULL)
		return (-1);
	for (i = 0; i < gm->no_box; i++) {
		get_box_coor(&x, &y, gm->map);
		gm->bx[i] = init_box((void *)&x, (void *)&y);
		if (gm->bx[i] == NULL) {
			return (-1);
		}
	}
	return (0);
}

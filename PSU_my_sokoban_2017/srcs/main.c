/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main file for sokoban
*/

#include "my_sokoban.h"

static void usage(char *fname)
{
	my_printf("USAGE\n"
		"\t%s map\n"
		"DESCRIPTION\n"
		"\tmap\tfile representing the warehouse map, containing"
		" '#' fir walls,\n\t\t'P' for the player, 'X' for the boxes"
		" and 'O' for storage locations.\n", fname);
	exit(0);
}

static int set_arg(char ch, char *fname)
{
	switch (ch) {
		case 'h':
			usage(fname);
			break;
		case '?':
			return (-1);
	}
	return (0);
}

static void draw_map(char **map)
{
	int	i = 0;
	int	j = 0;

	for (i = 0; map[i] != 0; i++) {
		for (j = 0; map[i][j] != '\0'; j++) {
			mvprintw(i, j, "%c", map[i][j]);
		}
	}
}

static int is_win(struct game *gm)
{
	unsigned int	i = 0;

	for (i = 0; i < gm->no_box; i++) {
		if (!gm->bx[i]->in_box)
			return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	char		ch = 0;
	unsigned int	i = 0;
	int		st = 0;
	struct game	gm;

	while ((ch = my_getopt(argc, argv, "h")) != -1)
		if (set_arg(ch, argv[0]) < 0)
			return (84);
	if (argc != 2 || init_game(argv, &gm) < 0)
		return (84);
	while (is_win(&gm)) {
		gm.p1->draw(gm.p1, &gm);
		for (i = 0; i < gm.no_box; i++)
			gm.bx[i]->draw(gm.bx[i], &gm);
		if (handle_event(getch(), &gm) < 0 || (st = is_blok(&gm)) > 0)
			break;
		draw_map(gm.map);
	}
	destroy(&gm);
	return (st);
}

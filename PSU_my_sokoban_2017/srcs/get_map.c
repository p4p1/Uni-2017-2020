/*
** EPITECH PROJECT, 2017
** get_map.c
** File description:
** <..>
*/

#include "my_sokoban.h"

char **get_map(char **argv, struct game *gm)
{
	int	fd = open(argv[my_optind], O_RDONLY);
	char	**map = (char **)malloc(sizeof(char *) * LINES + 1);
	int	j = 0;
	int	i = 0;

	if (fd < 0 || map == NULL)
		return (NULL);
	gm->no_box = 0;
	while (i < LINES) {
		map[i] = (char *)malloc(sizeof(char) * COLS);
		if (map[i] == NULL)
			return (NULL);
		my_fgets(map[i], COLS, fd);
		for (j = 0; map[i][j] != '\0'; j++)
			gm->no_box += (map[i][j] == 'X') ? 1 : 0;
		printw("%s", map[i]);
		++i;
	}
	map[i] = 0;
	return (map);
}

void get_player_coor(int *x_pos, int *y_pos, char **map)
{
	int	i = 0;
	int	j = 0;

	for (i = 0; map[i] != 0; i++) {
		for (j = 0; map[i][j] != '\0'; j++) {
			*x_pos = (map[i][j] == 'P') ? j : *x_pos;
			*y_pos = (map[i][j] == 'P') ? i : *y_pos;
			map[i][j] = (map[i][j] == 'P')? ' ': map[i][j];
		}
	}
}

static int line_is_box(int *x_pos, int *y_pos, char **map, int i)
{
	static int	j = 0;
	int		t_xpos = *x_pos;
	int		t_ypos = *y_pos;

	for (j = 0; map[i][j] != '\0'; j++) {
		*x_pos = (map[i][j] == 'X') ? j : *x_pos;
		*y_pos = (map[i][j] == 'X') ? i : *y_pos;
			map[i][j] = (map[i][j] == 'X')? ' ': map[i][j];
		if (*x_pos != t_xpos || *y_pos != t_ypos) {
			return (1);
		}
	}
	return (0);
}

void get_box_coor(int *x_pos, int *y_pos, char **map)
{
	static int	i = 0;

	for (i = 0; map[i] != 0; i++) {
		if (line_is_box(x_pos, y_pos, map, i))
			return;
	}
}

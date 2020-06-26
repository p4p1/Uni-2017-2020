/*
** EPITECH PROJECT, 2017
** map.c
** File description:
** <..>
*/

#include "my_runner.h"

int counter(char *fname)
{
	int	fd = open(fname, O_RDONLY);
	int	count = 0;
	char	ch = 0;

	if (fd < 0)
		return (0);
	while (read(fd, &ch, 1) > 0)
		if (ch == '1')
			count++;
	close(fd);
	return (count);
}

int mob_counter(char *fname)
{
	int	fd = open(fname, O_RDONLY);
	int	count = 0;
	char	ch = 0;

	if (fd < 0)
		return (0);
	while (read(fd, &ch, 1) > 0)
		if (ch == '2')
			count++;
	close(fd);
	return (count);
}

static void set_map(struct game *gm, char ch, int y_pos, int x_pos)
{
	static int	tile_count = 0;
	static int	mob_count = 0;

	if (mob_count == gm->set->no_mob)
		mob_count = 0;
	if (tile_count == gm->set->no_tile)
		tile_count = 0;
	if (ch == '1' && tile_count < gm->set->no_tile) {
		gm->ground[tile_count++] = create_tile(x_pos, y_pos,
				(y_pos < 300) ? TOP_PIPE : BOTTOM_PIPE);
	}
	if (ch == '2' && mob_count < gm->set->no_mob) {
		gm->mob[mob_count++] = create_mob(x_pos, y_pos);
	}
}

int create_map(struct game *gm, char *fname)
{
	int	fd = open(fname, O_RDONLY);
	char	ch = 0;
	int	x_pos = 0;
	int	y_pos = -300;

	if (fd < 0)
		return (-1);
	while (read(fd, &ch, 1) > 0) {
		x_pos += 100;
		if (ch == '\n') {
			x_pos = 0;
			y_pos += 100;
		}
		set_map(gm, ch, y_pos, x_pos);
	}
	close(fd);
	return (0);
}

/*
** EPITECH PROJECT, 2017
** map.c
** File description:
** retrieve map information
*/

#include "my_rpg.h"

static int wrong_head(header_t head)
{
	if (head.magic != 4386298)
		return (1);
	return (0);
}

static void set_player(tile_t tile, int *x_pos, int *y_pos)
{
	if (tile.type == PLAYER) {
		*x_pos = tile.x;
		*y_pos = tile.y;
	}
}

static map_info_t *set_tiles(map_info_t *info, unsigned int i,
		int *x_pos, int *y_pos, int fp)
{
	int		no = 1;

	for (unsigned int j = 0; j < info->head.width && no != 0; j++) {
		no = read(fp, &(info->map[i][j].tile), sizeof(tile_t));
		info->map[i][j].on_s = 0;
		if (no == 0)
			break;
		if (info->map[i][j].tile.type > MISC ||
				info->map[i][j].tile.type < TREE1)
			return (NULL);
		set_player(info->map[i][j].tile, x_pos, y_pos);
	}
	return (info);

}

map_info_t *get_map(char *path, int *x_pos, int *y_pos)
{
	int		fp = open(path, O_RDONLY);
	map_info_t	*info = malloc(sizeof(map_info_t));

	if (fp < 0 || info == NULL) {
		my_printf("%s: Can't find the file\n", path);
		return (NULL);
	}
	read(fp, &(info->head), sizeof(header_t));
	if (wrong_head(info->head))
		return (NULL);
	info->map = alloc_map(info->head);
	if (info->map == NULL)
		return (NULL);
	for (unsigned int i = 0; i < info->head.height; i++) {
		info = set_tiles(info, i, x_pos, y_pos, fp);
		if (info == NULL)
			return (NULL);
	}
	return (info);
}

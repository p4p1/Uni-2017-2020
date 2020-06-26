/*
** EPITECH PROJECT, 2017
** init.c
** File description:
** <..>
*/

#include "navy.h"

static char **create_empty_map(void)
{
	char	**tmp = (char **)malloc(sizeof(char *) * SIZE + 1);
	int	i = 0;

	if (tmp == NULL)
		return (NULL);
	for (i = 0; i < SIZE; i++) {
		tmp[i] = my_strdup(". . . . . . . .");
		if (tmp[i] == NULL)
			return (NULL);
	}
	tmp[i] = NULL;
	return (tmp);
}

static struct boat get_boat(char *line)
{
	struct boat bt = { 0, 0, 0, 0, 0 };

	if (my_strlen(line) != 7 || is_not_ltr(line[2]) || is_not_ltr(line[5])
			|| is_not_no(line[3]) || is_not_no(line[6]))
		return (bt);
	bt.size = my_atoi(line);
	bt.posx_ini = line[2] - 65;
	bt.posy_ini = (line[3] - 48) - 1;
	bt.posx_final = line[5] - 65;
	bt.posy_final = (line[6] - 48) - 1;
	return (bt);
}

static int place_boats(char **map, int fd)
{
	char	*buffer = (char *)malloc(sizeof(char) * BUFSIZ);
	struct boat	bt = { 0, 0, 0, 0, 0 };
	int		boat_no = 0;
	int		boat_done = 0;

	buffer = my_fgets(buffer, BUFSIZ, fd);
	while (buffer && boat_no < 4) {
		bt = get_boat(buffer);
		if (bt.size == 0)
			return (-1);
		if (((boat_done >> bt.size) & 1) == 1)
			return (-1);
		boat_done |= 1 << bt.size;
		if (set_boat(bt, map) < 0)
			return (-1);
		buffer = my_fgets(buffer, BUFSIZ, fd);
		boat_no++;
	}
	return ((boat_no == 4) ? 0 : -1);
}

struct player_data *init(char *path)
{
	struct player_data	*pd = malloc(sizeof(struct player_data));
	int			fd = 0;

	if (pd == NULL || path == NULL)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	pd->user = getpid();
	pd->u_map = create_empty_map();
	pd->e_map = create_empty_map();
	pd->is_win = 0;
	if (pd->u_map == NULL || pd->e_map == NULL)
		return (NULL);
	if (place_boats(pd->u_map, fd) < 0)
		return (NULL);
	cdat = NULL;
	return (pd);
}

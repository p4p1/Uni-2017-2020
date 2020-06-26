/*
** EPITECH PROJECT, 2017
** init.c
** File description:
** <..>
*/

#include "connect4.h"

static struct game *set_default(struct game *gm)
{
	gm->width = 7;
	gm->height = 6;
	gm->p1 = 'X';
	gm->p2 = 'O';
	gm->end = '#';
	return (gm);
}

static char **set_map(struct game *gm)
{
	char	**map = malloc(sizeof(char *) * (gm->height + 1));
	int	j = 0;
	int	i = 0;

	if (map == NULL)
		return (NULL);
	for (i = 0 ; i < gm->height; i++) {
		map[i] = malloc(sizeof(char) * (gm->width + 1));
		if (map[i] == NULL)
			return (NULL);
		for (j = 0; j < gm->width; j++)
			map[i][j] = '.';
		map[i][j] = '\0';
	}
	map[i] = NULL;
	return (map);
}

static struct game *error_detc(struct game *gm)
{
	if (gm->width > 80 || gm->height > 16 ||
			(gm->width * gm->height) < 20) {
		my_printf("Not a valid size\n");
		return (destroyer(gm));
	}
	gm->map = set_map(gm);
	if (gm->map == NULL) {
		write(2, "Not enough memory\n", 18);
		return (destroyer(gm));
	}
	if (gm->p1 == gm->p2 || gm->p1 == gm->end || gm->p2 == gm->end) {
		my_printf("Invalid char\n");
		return (destroyer(gm));
	}
	return (gm);
}

static int is_valid_arg(char *av)
{
	char	val[5] = "whpa\0";

	if (my_strlen(av) != 2 && my_strlen(av) != 3)
		return (0);
	if (av[0] != '-')
		return (0);
	for (int i = 0; i < 4; i++) {
		if (av[1] == 'p' && av[2] != '1' && av[2] != '2')
			return (0);
		if (av[1] == val[i])
			return (1);
	}
	return (0);
}

struct game *init(int ac, char **av)
{
	struct game	*gm = malloc(sizeof(struct game));

	if (gm == NULL)
		return (NULL);
	my_memset(gm, 0, sizeof(struct game));
	gm = set_default(gm);
	for (int i = 1; i < ac; i++) {
		if (is_valid_arg(av[i])) {
			gm = parse_arg(gm, av, &i);
		} else {
			my_printf("%s: Not a valid argument\n", av[i]);
			return (destroyer(gm));
		}
	}
	return (error_detc(gm));
}

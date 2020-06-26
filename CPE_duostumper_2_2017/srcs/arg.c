/*
** EPITECH PROJECT, 2017
** arg.c
** File description:
** <..>
*/

#include "connect4.h"

static struct game *get_size(struct game *gm, char *av, char ch)
{
	if (ch == 'w')
		gm->width = my_atoi(av);
	if (ch == 'h')
		gm->height = my_atoi(av);
	return (gm);
}

static struct game *get_char_usr(struct game *gm, char *av, char *ch)
{
	if (ch[1] == 'a')
		gm->end = av[0];
	if (ch[1] == 'p' && ch[2] == '1') {
		gm->p1 = av[0];
	}
	if (ch[1] == 'p' && ch[2] == '2')
		gm->p2 = av[0];
	return (gm);
}

struct game *parse_arg(struct game *gm, char **av, int *i)
{
	if (av[*i][1] == 'w' || av[*i][1] == 'h')
		gm = get_size(gm, av[*i + 1], av[*i][1]);
	if (av[*i][1] == 'a' || av[*i][1] == 'p')
		gm = get_char_usr(gm, av[*i + 1], av[*i]);
	*i += 1;
	return (gm);
}

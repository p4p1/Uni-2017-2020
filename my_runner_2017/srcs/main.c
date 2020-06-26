/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main file for my_runner
*/

#include "my_runner.h"

static int usage(char *name)
{
	my_printf("Finite runner created with CSFML.\n\n"
		"USAGE\n\t%s map.txt\n\n\n"
		"OPTIONS\n\t-i\tgot to infinty and beyond\n"
		"\t-h\tprint the usage and quit.\n\n"
		"USER INTERACTIONS\n\tSPACE_KEY\tjump.\n", name);
	return (84);
}

static struct settings *create_settings(void)
{
	struct settings	*st = malloc(sizeof(struct settings));

	if (st == NULL)
		return (NULL);
	st->no_tile = 0;
	st->infin_mode = 0;
	st->no_mob = 0;
	return (st);
}

static int set_arg(char ch, char *name, struct settings *st)
{
	switch (ch) {
		case 'h':
			usage(name);
			break;
		case 'i':
			st->infin_mode = 1;
			break;
		case '?':
			return (-1);
		default:
			return (-1);
	}
	return (0);
}

static int loop(char **av, struct game *gm)
{
	int	no = 0;

	while ((no = menu(gm)) > 0) {
		if (no == 2 && info(gm) > 0)
			continue;
		else if(no == 2)
			break;
		if (no == 1 && main_game(gm) < 0)
			break;
		if (death(gm) == -1)
			break;
		if (create_elem(av[my_optind], gm) < 0)
			return (84);
	}
	return (0);
}

int main(int ac, char **av)
{
	char		ch;
	struct game	*gm = NULL;
	struct settings	*st = create_settings();

	if (ac != 2)
		return (usage(av[0]));
	while ((ch = my_getopt(ac, av, "hi")) != -1)
		if (set_arg(ch, av[0], st) < 0)
			return (84);
	gm = init(av[(!my_optind) ? 1 : my_optind], st);
	if (gm == NULL)
		return (84);
	return (loop(av, gm));
}

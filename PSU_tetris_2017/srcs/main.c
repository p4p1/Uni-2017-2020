/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main file
*/

#include "tetris.h"

int main(int ac, char **av)
{
	int			ch = 0;
	int			i = 0;
	int			no = 0;
	struct option		*op = init_options();
	struct queue		*qu = NULL;
	struct args		*arg = init_arg(av[0]);

	setupterm(NULL, 0, NULL);
	while ((ch = getopt_long(ac, av, "hL:l:r:t:d:q:p:m:wD", op, &i)) > 0) {
		no = call_tab(ch, arg);
		if (no == -1)
			return (0);
		else if (no == -2)
			return (84);
	}
	qu = get_files("tetriminos/");
	bubble_sort(qu);
	if (arg->debug_flag)
		debug_mode(arg, qu);
	return (0);
}

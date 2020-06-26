/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** <..>
*/

#include "corewar.h"

static void usage(char *fname)
{
	my_printf("USAGE\n\t%s file_name[.s]\n\nDESCRIPTION\n\tfile_name\t"
		"file in assembly language to be converted into file_name.core"
		", an\n\t\t\texecutable in the Virtual Machine.\n", fname);
	exit(0);
}

static void small_usage(char *fname)
{
	my_printf("Usage: %s file_name[.s] ....\n", fname);
	exit(0);
}

static int check_opt(int ch, char *fname)
{
	if (ch == 'h')
		usage(fname);
	if (ch == '?')
		return (-1);
	return (0);
}

int main(int ac, char **av)
{
	struct d_queue	*qu = NULL;
	int		ch = 0;

	while ((ch = my_getopt(ac, av, "h")) != -1)
		if (check_opt(ch, av[0]) == -1)
			return (84);
	if (my_optind == 0)
		small_usage(av[0]);
	for (int i = my_optind; i < ac; i++) {
		qu = lex_file(av[i]);
		if (qu == NULL) {
			// Free d_queue
			continue;
		}
	}
	return (0);
}

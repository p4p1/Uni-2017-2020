/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main file for the bistromatic
*/
#include "bistro.h"

static void check_base(char const *);
static void check_ops(char const *);
static char *get_expr(unsigned int);
static void process_args(int , char **);

int main(int ac, char **av)
{
	unsigned int	size = 0;
	char	*expr = 0;
	char	*sol = 0;

	process_args(ac, av);
	check_base(av[1]);
	check_ops(av[2]);
	size = my_getnbr(av[3]);
	expr = get_expr(size);
	sol = eval_expr(av[1], av[2], expr, size);
	if (sol == 0)
		my_putstr(SYNTAX_ERROR_MSG);
	else
		my_putstr(sol);
	return (EXIT_SUCCESS);
}

static void process_args(int argc, char **argv)
{
	if (argc == 2) {
		if (!my_strcmp(argv[1], "-h")) {
			usage_description(argv[0]);
			exit(EXIT_SUCCESS);
		}
	}
	if (argc != 4) {
		my_putstr("Usage: ");
		my_putstr(argv[0]);
		my_putstr(" base ops \"()+_*/%\" exp_len\n");
		exit (EXIT_USAGE);
	}
}

static void check_base(char const *b)
{
	if (my_strlen(b) < 2) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_BASE);
	}
}

static char *get_expr(unsigned int size)
{
	char *expr;

	if (size <= 0) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_SIZE_NEG);
	}
	expr = malloc(size + 1);
	if (expr == 0) {
		my_putstr(ERROR_MSG);
		exit (EXIT_MALLOC);
	}
	if (read(0, expr, size) != size) {
		my_putstr(ERROR_MSG);
		exit(EXIT_READ);
	}
	expr[size] = 0;
	return (expr);
}

static void check_ops(char const *ops)
{
	if (my_strlen(ops) != 7) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_OPS);
	}
}

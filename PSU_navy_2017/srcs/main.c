/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** <..>
*/

#include "navy.h"

static int process_arg(char ch, char *name)
{
	if (ch == 'h') {
		my_printf("USAGE\n"
			"\t%s [first_player_id] navy_positions\n"
			"DESCRIPTION\n"
			"\tfirst_player_pid: only for the 2nd player."
			"\tpid of the first player.\n"
			"\tnay_positions: file representing the position of the"
			"ships.\n", name);
		return (1);
	}
	if (ch == '?') {
		my_printf("Unknow arg: %c\n", my_optopt);
		return (85);
	}
	return (0);
}

static int win(struct player_data *pd)
{
	if (is_win(pd->u_map)) {
		my_printf("my positions:\n");
		disp_map(pd->u_map);
		my_printf("enemy's positions:\n");
		disp_map(pd->e_map);
		my_printf("Enemy won\n");
		pd->is_win = 1;
		return (0);
	}
	if (is_win(pd->e_map)) {
		my_printf("my positions:\n");
		disp_map(pd->u_map);
		my_printf("enemy's positions:\n");
		disp_map(pd->e_map);
		my_printf("I won\n");
		pd->is_win = 1;
		return (0);
	}
	return (0);
}

static void game(struct player_data *pd, int ac)
{
	char	*buf = (char *)malloc(sizeof(char) * BUFSIZ);
	static int	turn = 0;

	if (buf == NULL)
		return;
	turn = (turn == 0) ? ac : turn;
	while (!pd->is_win && buf) {
		my_printf("my positions:\n");
		disp_map(pd->u_map);
		my_printf("enemy's positions:\n");
		disp_map(pd->e_map);
		if ((turn++ % 2) == 0) {
			my_printf("attack: ");
			buf = my_fgets(buf, BUFSIZ, 0);
			send_data(pd, &buf);
		} else {
			my_printf("waiting for enemy’s attack...\n");
			wait_data(pd);
		}
		win(pd);
	}
}

int main(int ac, char **av)
{
	char	ch = 0;
	struct player_data	*pd = NULL;

	if (ac != 2 && ac != 3)
		return (84);
	while ((ch = my_getopt(ac, av, "h")) != -1)
		if ((ch = process_arg(ch, av[0])) != 0)
			return (ch - 1);
	pd = init((ac == 3) ? av[my_optind + 1] : av[my_optind]);
	if (pd == NULL)
		return (84);
	setup_connection(pd, ac, av);
	game(pd, ac);
	return (0);
}

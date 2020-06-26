/*
** EPITECH PROJECT, 2017
** connect.c
** File description:
** <..>
*/

#include "navy.h"

static void sighandler(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (cdat == NULL) {
		cdat = init_cdat(siginfo->si_pid);
		return;
	}
	if (cdat != NULL && cdat->stat == RECEIVING) {
		is_good(sig);
	}
	if (cdat != NULL && cdat->stat == WAITING) {
		create_signal(sig);
		if (cdat->current_bit == 6) {
			cdat->current_bit = 0;
			cdat->posy = cdat->posy >> 1;
			cdat->posx = cdat->posx >> 1;
			cdat->stat = READY;
		}
	}
}

void setup_connection(struct player_data *pd, int ac, char **av)
{
	struct sigaction	act;

	my_printf("my_pid: %d\n", pd->user);
	act.sa_sigaction = &sighandler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	if (ac == 2) {
		my_printf("waiting for enemy connexion...\n");
		while (cdat == NULL);
		my_printf("\nenemy connected\n");
		pd->enemy = cdat->enemy;
	} else {
		cdat = init_cdat(my_atoi(av[1]));
		cdat->stat = WAITING;
		cdat->player = PLAYER2;
		pd->enemy = my_atoi(av[1]);
		kill(pd->enemy, SIGUSR1);
		my_printf("successfully connected\n");
	}
	my_putchar('\n');
}

void send_data(struct player_data *pd, char **str)
{
	while (*str && !good_input(*str, pd->e_map)) {
		my_printf("wrong position\n");
		my_printf("attack: ");
		*str = my_fgets(*str, BUFSIZ, 0);
		if (*str == NULL)
			return;
	}
	if (*str != NULL) {
		cdat->posx = str[0][0] - 65;
		cdat->posy = str[0][1] - 49;
		cdat->stat = RECEIVING;
		send_signal();
		while (cdat->stat == RECEIVING);
		if (cdat->stat == HIT)
			place_map(pd->e_map, cdat->posx * 2, cdat->posy, 'x');
		else
			place_map(pd->e_map, cdat->posx, cdat->posy, 'o');
		cdat->stat = WAITING;
		cdat->posx = 0;
		cdat->posy = 0;
	}
}

void wait_data(struct player_data *pd)
{
	cdat->current_bit = 0;
	while (cdat->stat == WAITING);
	if (is_hit(pd->u_map, cdat->posx, cdat->posy)) {
		my_printf("%c%c: hit\n\n", cdat->posx + 65, cdat->posy + 49);
		kill(cdat->enemy, SIGUSR1);
		place_map(pd->u_map, cdat->posx * 2, cdat->posy, 'x');
	} else {
		my_printf("%c%c: missed\n\n", cdat->posx + 65, cdat->posy + 49);
		kill(cdat->enemy, SIGUSR2);
	}
	cdat->posx = 0;
	cdat->posy = 0;
}

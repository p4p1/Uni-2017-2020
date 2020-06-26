/*
** EPITECH PROJECT, 2017
** cdat.c
** File description:
** <..>
*/

#include "navy.h"

int good_input(char *str, char **map)
{
	if (my_strlen(str) != 2)
		return (0);
	if (str[0] < 'A' || str[0] > 'H')
		return (0);
	if (str[1] < '1' || str[1] > '8')
		return (0);
	if (str[0] - 65 < 0 || str[0] - 65 > 7)
		return (0);
	if (str[1] - 49 < 0 || str[1] - 49 > 7)
		return (0);
	if (map[str[0] - 65][(str[1] - 49) * 2] != '.')
		return (0);
	return (1);
}

void send_signal(void)
{
	struct timespec tim, tim2;

	tim.tv_sec = 0;
	tim.tv_nsec = 500000L;
	for (int i = 2; i >= 0; i--) {
		if (((cdat->posx >> i) & 1) == 1) {
			kill(cdat->enemy, SIGUSR1);
		} else {
			kill(cdat->enemy, SIGUSR2);
		}
		nanosleep(&tim , &tim2);
	}
	nanosleep(&tim , &tim2);
	for (int i = 2; i >= 0; i--) {
		if (((cdat->posy >> i) & 1) == 1) {
			kill(cdat->enemy, SIGUSR1);
		} else {
			kill(cdat->enemy, SIGUSR2);
		}
		nanosleep(&tim , &tim2);
	}
}

void create_signal(int sig)
{
	if (cdat->current_bit < 3) {
		if (sig == SIGUSR1) {
			cdat->posx |= 1;
		} else {
			cdat->posx |= 0;
		}
		cdat->posx = cdat->posx << 1;
	}
	if (cdat->current_bit >= 3) {
		if (sig == SIGUSR1) {
			cdat->posy |= 1;
		} else {
			cdat->posy |= 0;
		}
		cdat->posy = cdat->posy << 1;
	}
	cdat->current_bit++;
}

struct connection_data *init_cdat(pid_t en)
{
	struct connection_data *tmp = malloc(sizeof(struct connection_data));

	if (tmp == NULL)
		return (NULL);
	tmp->stat = READY;
	tmp->posx = 0;
	tmp->posy = 0;
	tmp->enemy = en;
	tmp->current_bit = 0;
	tmp->player = PLAYER1;
	return (tmp);
}

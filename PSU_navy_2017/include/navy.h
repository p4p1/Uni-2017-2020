/*
** EPITECH PROJECT, 2017
** navy.h
** File description:
** <..>
*/

#ifndef NAVY_H_
#define NAVY_H_

#include "my.h"
#include "my_getopt.h"
#include "my_fgets.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>

#define SIZE 8

enum status {
	RECEIVING,
	WAITING,
	READY,
	HIT,
	PLAYER1,
	PLAYER2
};

struct boat {
	int	size;
	int	posx_ini;
	int	posy_ini;
	int	posx_final;
	int	posy_final;
};

struct connection_data {
	enum status	stat;
	enum status	player;
	int	current_bit;
	int	posx;
	int	posy;
	pid_t	enemy;
};

struct player_data {
	int		is_win;
	char		**u_map;
	char		**e_map;
	pid_t		user;
	pid_t		enemy;
};

struct connection_data *cdat;

struct player_data *init(char *);
struct connection_data *init_cdat(pid_t);
int good_input(char *, char **);
int set_boat(struct boat, char **);
void setup_connection(struct player_data *, int, char **);
void disp_map(char **);
void wait_data(struct player_data *);
void send_data(struct player_data *, char **);
void send_signal(void);
void create_signal(int);
int is_hit(char **, int, int);
void place_map(char **, int, int, char);
void is_good(int);
int is_win(char **);
int is_not_no(char);
int is_not_ltr(char);

#endif

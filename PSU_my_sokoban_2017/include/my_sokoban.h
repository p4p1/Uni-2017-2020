/*
** EPITECH PROJECT, 2017
** my_sokoban.h
** File description:
** header file for my_sokoban
*/

#ifndef MY_SOKOBAN
#define MY_SOKOBAN

#include "my.h"
#include "my_getopt.h"
#include "my_fgets.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ncurses.h>

typedef struct __entity__ Player_t;
typedef struct __entity__ Box_t;
struct game;

struct __entity__
{
	int	x;
	int	y;
	int	initial_x;
	int	initial_y;
	char	ch;
	int	in_box;
	void	(*reset)(Player_t *);
	void	(*draw)(Player_t *, struct game *);
	void	(*move_pos)(Player_t *, struct game *, int, int);
	void	(*disp)(Player_t *);
};

struct game
{
	Player_t	*p1;
	Box_t		**bx;
	char		**map;
	unsigned int	no_box;
};

Player_t *init_player(void *, void *);
Box_t *init_box(void *, void *);
int handle_event(char, struct game *);
int init_game(char **, struct game *);
char **get_map(char **, struct game *);
void destroy(struct game *);
int is_blok(struct game *);
void get_box_coor(int *, int *, char **);
int get_box(struct game *, int, int);
void get_player_coor(int *, int *, char **);

#endif

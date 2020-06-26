/*
** EPITECH PROJECT, 2017
** connect4.h
** File description:
** connect4 header
*/

#ifndef CONNECT4_H_
#define CONNECT4_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "my_fgets.h"

struct game {
	char	**map;
	int	width;
	int	height;
	char	p1;
	char	p2;
	char	end;
};

// Init
struct game *init(int, char **);
struct game *parse_arg(struct game *, char **, int *);
void *destroyer(struct game *);

// Map
void display_map(struct game *);
int is_winner(struct game *, int, int, char);

// GamePlay
int is_over(struct game *);
int  rep_right(struct game *gm, int posx, int posy);
int  rep_left(struct game *gm, int posx, int posy);
int  rep_down(struct game *gm, int posx, int posy);
int  diag_rdow(struct game *gm, int posx, int posy);
int  diag_rup(struct game *gm, int posx, int posy);
int  diag_lup(struct game *gm, int posx, int posy);
int  diag_ldow(struct game *gm, int posx, int posy);

// Lib
void my_memset(void *, int, unsigned int);

#endif

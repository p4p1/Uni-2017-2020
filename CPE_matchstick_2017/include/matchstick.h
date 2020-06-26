/*
** EPITECH PROJECT, 2017
** matchstick.h
** File description:
** voilas cest le matchstick <3
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include "my.h"
#include "my_getopt.h"
#include "my_fgets.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum {
	USER=1,
	AI=2
};

struct pos {
	int	line;
	int	no_match;
};

struct matchstick_s {
	char	**tab;
	int	rt;
	int	max_line_size;
	int	no_lines;
	int	max_remove_no;
};

struct matchstick_s *init_matchstick(int, char **);
struct pos infi(struct matchstick_s *, struct pos);
int user_play(struct matchstick_s *);
int bot_play(struct matchstick_s *);
int can_remove(struct matchstick_s *, int, int);
int sum_nim(char **, int);
char **dup_tab(char **, int);
char **tmp_remove_match(struct matchstick_s *, int, int);
int destroy_matchstick(struct matchstick_s *);
void display_map(char **, int);
void remove_match(struct matchstick_s *, int, int);

#endif

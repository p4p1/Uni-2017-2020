/*
** EPITECH PROJECT, 2017
** tetris.h
** File description:
** tetris header
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <getopt.h>
#include <ncurses.h>
#include <term.h>
#include <dirent.h>

#include "my.h"
#include "clist.h"
#include "my_fgets.h"

#define JUMP_TABLE_SUB ('D')

struct args {
	int		level;
	int		*map_size;
	int		key_left_b;
	int		key_right_b;
	int		key_turn_b;
	int		key_drop_b;
	int		key_quit_b;
	int		key_pause_b;
	unsigned int	debug_flag;
	unsigned int	without_next_flag;
	char		*prog_name;
};

struct shapes {
	unsigned int	width;
	unsigned int	height;
	unsigned int	error_flag;
	int		color;
	char		**shape;
	char		*name;
	int		no;
};

struct option *init_options(void);
struct args *init_arg(char *);
void debug_mode(struct args *, struct queue *);

// Parser
struct shapes *get_shape_from_file(char *);
int is_line_size(char *);
int is_tetrimino_line(char *);
int dot_pos(char *);
int skip_slash(char *);
void bubble_sort(struct queue *);

// ls
struct queue *get_files(char *);

// Arguments
int call_tab(char ch, struct args *);
struct args *argument_big_d(struct args *);
struct args *argument_big_l(struct args *);
struct args *argument_smo_d(struct args *);
struct args *argument_smo_h(struct args *);
struct args *argument_smo_l(struct args *);
struct args *argument_smo_m(struct args *);
struct args *argument_smo_p(struct args *);
struct args *argument_smo_q(struct args *);
struct args *argument_smo_r(struct args *);
struct args *argument_smo_t(struct args *);
struct args *argument_smo_w(struct args *);

#endif

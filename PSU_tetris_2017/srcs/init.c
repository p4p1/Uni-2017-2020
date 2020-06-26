/*
** EPITECH PROJECT, 2017
** init.c
** File description:
** <..>
*/

#include "tetris.h"

struct option *init_options(void)
{
	static struct option long_options[12] = {
		{ "help", no_argument, 0, 'h' },
		{ "level", required_argument, 0, 'L' },
		{ "key-left", required_argument, 0, 'l' },
		{ "key-right", required_argument, 0, 'r' },
		{ "key-turn", required_argument, 0, 't' },
		{ "key-drop", required_argument, 0, 'd' },
		{ "key-quit", required_argument, 0, 'q' },
		{ "key-pause", required_argument, 0, 'p' },
		{ "map-size", required_argument, 0, 'm' },
		{ "without-next", no_argument, 0, 'w' },
		{ "debug", no_argument, 0, 'D' },
		{ 0, 0, 0, 0}
	};

	return (long_options);
}

struct args *init_arg(char *prog_name)
{
	struct args		*arg = malloc(sizeof(struct args));

	if (arg == NULL)
		return (NULL);
	arg->level = 1;
	arg->map_size = malloc(sizeof(int) * 2);
	if (arg->map_size == NULL)
		return (NULL);
	arg->map_size[0] = 20;
	arg->map_size[1] = 10;
	arg->debug_flag = 0;
	arg->without_next_flag = 0;
	arg->key_left_b = KEY_LEFT;
	arg->key_right_b = KEY_RIGHT;
	arg->key_turn_b = KEY_UP;
	arg->key_drop_b = KEY_DOWN;
	arg->key_quit_b = 'q';
	arg->key_pause_b = ' ';
	arg->prog_name = prog_name;
	return (arg);
}

/*
** EPITECH PROJECT, 2017
** big.c
** File description:
** <..>
*/

#include "tetris.h"

struct args *argument_big_l(struct args *self)
{
	if (self == NULL)
		return (NULL);
	self->level = my_atoi(optarg);
	return (self);
}

struct args *argument_big_d(struct args *self)
{
	if (self == NULL)
		return (NULL);
	if (self->debug_flag)
		self->debug_flag = 0;
	else
		self->debug_flag = 1;
	return (self);
}

/*
** EPITECH PROJECT, 2017
** smol_q_to_w.c
** File description:
** <..>
*/

#include "tetris.h"

struct args *argument_smo_q(struct args *self)
{
	int	i = 0;

	if (self == NULL)
		return (NULL);
	while (optarg[i] < 0)
		i++;
	self->key_quit_b = optarg[i];
	return (self);
}

struct args *argument_smo_r(struct args *self)
{
	int	i = 0;

	if (self == NULL)
		return (NULL);
	while (optarg[i] < 0)
		i++;
	self->key_right_b = optarg[i];
	return (self);
}

struct args *argument_smo_t(struct args *self)
{
	int	i = 0;

	if (self == NULL)
		return (NULL);
	while (optarg[i] < 0)
		i++;
	self->key_turn_b = optarg[i];
	return (self);
}

struct args *argument_smo_w(struct args *self)
{
	if (self == NULL)
		return (NULL);
	if (self->without_next_flag)
		self->without_next_flag = 0;
	else
		self->without_next_flag = 1;
	return (self);
}

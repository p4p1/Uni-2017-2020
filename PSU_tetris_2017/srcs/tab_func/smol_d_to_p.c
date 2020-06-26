/*
** EPITECH PROJECT, 2017
** smol_d_to_p.c
** File description:
** <..>
*/

#include "tetris.h"

struct args *argument_smo_d(struct args *self)
{
	int	i = 0;

	if (self == NULL)
		return (NULL);
	while (optarg[i] < 0)
		i++;
	self->key_drop_b = optarg[i];
	return (self);
}

struct args *argument_smo_h(struct args *self)
{
	if (self == NULL)
		return (NULL);
	my_printf("Usage:\t%s [options]\n"
	"Options:\n"
	" --help\t\t\tDisplay this help\n"
	" -L --level={num}\tStart Tetris at level num (def: 1)\n"
	" -l --key-left={K}\tMove the tetrimino LEFT using the K key"
	"(def: left arrow)\n -r --key-right={K}\tMove the tetrimino RIGHT"
	"using the K key (def: right arrow)\n"
	" -t --key-turn={K}\tTURN the tetrimino clockwise 90d using the K"
	" key (def: top arrow)\n -d --key-drop={K}\tDROP the tetrimino using"
	"the K key (def: down arrow)\n -q --key-quit={K}\tQUIT the game using"
	"the K key (def: 'q' key)\n -p --key-pause={K}\tPAUSE/RESTART the"
	" game using the K key (def: space bar)\n --map-size={row,col}\t"
	"Set the numbers of rows and columns of the map (def: 20,10)\n "
	"-w --without-next\tHide next"
	" tetrimino (def: false)\n -D --debug\t\tDebug mode (def: false)\n",
	self->prog_name);
	return (NULL);
}

struct args *argument_smo_l(struct args *self)
{
	int	i = 0;

	if (self == NULL)
		return (NULL);
	while (optarg[i] < 0)
		i++;
	self->key_left_b = optarg[i];
	return (self);
}

struct args *argument_smo_m(struct args *self)
{
	int	i = 0;

	if (self == NULL)
		return (NULL);
	self->map_size[0] = my_atoi(optarg);
	for (i = 0; optarg[i] != ',' && optarg[i]; i++)
		;
	if (optarg[i] == '\0')
		return (NULL);
	self->map_size[1] = my_atoi(optarg + i + 1);
	return (self);
}

struct args *argument_smo_p(struct args *self)
{
	int	i = 0;

	if (self == NULL)
		return (NULL);
	while (optarg[i] < 0)
		i++;
	self->key_pause_b = optarg[i];
	return (self);
}

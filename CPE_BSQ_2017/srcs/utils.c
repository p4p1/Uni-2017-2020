/*
** EPITECH PROJECT, 2017
** utils.c
** File description:
** <..>
*/

#include "bsq.h"

char *end_first_line(char *buf, int i)
{
	if (buf != NULL) {
		buf[i] = '\n';
		buf[i + 1] = '\0';
		return (buf);
	}
	return (NULL);
}

int valid_line(char *line, int size)
{
	int	i = 0;

	if (line == NULL && size < 0)
		return (0);
	for (i = 0; line[i] != '\0' && i <= size && line[i] != '\n'; i++) {
		if (line[i] != '.' && line[i] != 'o')
			return (0);
	}
	if (i > size)
		return (0);
	return (1);
}

bsq_class *set_to_zero(bsq_class *self)
{
	int	i = 0;

	self->pos.x = 0;
	self->pos.y = 0;
	self->bigest_pos.x = 0;
	self->bigest_pos.y = 0;
	for (i = 0; i < self->size.height; i++) {
		self->map[i] = 0;
		self->sol[i] = 0;
	}
	return (self);
}

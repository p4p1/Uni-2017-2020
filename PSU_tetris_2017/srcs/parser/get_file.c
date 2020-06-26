/*
** EPITECH PROJECT, 2017
** get_file.c
** File description:
** <..>
*/

#include "tetris.h"

static void save_size(struct shapes *self, char *line)
{
	int		i = 0;

	if (self->error_flag)
		return;
	self->width = my_atoi(line);
	for (i = 0; line[i] && line[i] != ' '; i++)
		;
	self->height = my_atoi(line + i + 1);
	for (i = i + 1; line[i] && line[i] != ' '; i++)
		;
	self->color = my_atoi(line + i + 1);
	self->shape = malloc(sizeof(char *) * (self->height + 1));
	if (self->shape == NULL)
		return;
	for (i = 0; i < (int) self->height; i++) {
		self->shape[i] = malloc(sizeof(char) * (self->width + 1));
		my_memset(self->shape[i], 0, self->width + 1);
	}
	self->shape[i] = NULL;
}

static void save_shape(struct shapes *self, char *line, int pos)
{
	int	i = 0;

	if (self->error_flag || pos > (int)self->height)
		return;
	for (i = 0; line[i]; i++) {
		self->shape[pos][i] = line[i];
	}
	while (self->shape[pos][i - 1] != '*')
		i--;
	self->shape[pos][i] = '\0';
}

struct shapes *get_shape_from_file(char *fname)
{
	struct shapes	*self = malloc(sizeof(struct shapes));
	char		*buf = malloc(sizeof(char) * BUFSIZ);
	int		fd = open(fname, O_RDONLY);
	int		pos = skip_slash(fname);
	int		j = 0;

	if (self == NULL || buf == NULL || fd < 0)
		return (NULL);
	my_memset(self, 0, sizeof(struct shapes));
	self->name = my_strdup_ln(fname + pos, dot_pos(fname + pos));
	self->error_flag = 0;
	buf = my_fgets(buf, BUFSIZ, fd);
	while (buf) {
		if (is_line_size(buf))
			save_size(self, buf);
		else if (is_tetrimino_line(buf))
			save_shape(self, buf, j++);
		else
			self->error_flag = 1;
		buf = my_fgets(buf, BUFSIZ, fd);
	}
	return (self);
}

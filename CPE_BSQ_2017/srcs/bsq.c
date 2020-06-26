/*
** EPITECH PROJECT, 2017
** bsq.c
** File description:
** the bsq algorithm
*/

#include "bsq.h"

static int no_to_place(bsq_class *s, char ch)
{
	int	up;
	int	ri;
	int	ur;

	if (ch == 'o')
		return (0);
	if ((s->pos.y - 1) >= 0 && (s->pos.x - 1) >= 0) {
		up = s->sol[s->pos.y - 1][s->pos.x];
		ri = s->sol[s->pos.y][s->pos.x - 1];
		ur = s->sol[s->pos.y - 1][s->pos.x - 1];
		if (up < ri && up < ur)
			return (up + 1);
		if (ri < up && ri < ur)
			return (ri + 1);
		if (ur <= up && ur <= ri)
			return (ur + 1);
	}
	return (1);
}

static void fp_scan_line(bsq_class *s)
{
	int	ch = 0;

	s->sol[s->pos.y] = (int *)malloc(sizeof(int) * s->size.width - 1);
	if (s->sol[s->pos.y] == 0)
		return;
	for (int i = 0; i < s->size.width - 1; i++)
		s->sol[s->pos.y][i] = 0;
	for (s->pos.x = 0; s->map[s->pos.y][s->pos.x] != '\n'; s->pos.x++) {
		ch = s->map[s->pos.y][s->pos.x];
		if (ch != 'o') {
			s->sol[s->pos.y][s->pos.x] = no_to_place(s, ch);
			if (s->sol[s->pos.y][s->pos.x] >
				s->sol[s->bigest_pos.y][s->bigest_pos.x]) {
				s->bigest_pos.y = s->pos.y;
				s->bigest_pos.x = s->pos.x;
			}
		}
	}
	s->pos.y += 1;
}

static char *get_first_line(bsq_class *self)
{
	char	ch = 0;
	int	bufsize = 1024;
	unsigned int	i = 0;
	char	*buf = (char *)malloc(sizeof(char) * bufsize);
	char	*tmp = 0;

	if (self->map[0] != 0 || buf == NULL)
		return (NULL);
	while ((ch = my_getchar_fd(self->fd)) != '\n') {
		if ((i % 1023) == 0) {
			tmp = (char *)malloc(sizeof(char) * bufsize);
			my_strcpy(tmp, buf);
			free(buf);
			buf = (char *)malloc(sizeof(char) * (bufsize *= 2));
			my_strcpy(buf, tmp);
			free(tmp);
		}
		buf[i++] = ch;
	}
	self->size.width = i + 1;
	return (end_first_line(buf, i));
}

static char *fp_get_line(bsq_class *self)
{
	char	*line = NULL;

	if (self == NULL)
		return (NULL);
	if (self->map[0] == 0) {
		line = get_first_line(self);
	} else {
		line = (char *)malloc(sizeof(char) * self->size.width + 1);
		if (line == NULL)
			return (NULL);
		my_fgets(line, self->size.width, self->fd);
		if (my_strlen(line) != self->size.width )
			return (NULL);
	}
	if (line != NULL && valid_line(line, self->size.width))
		return (line);
	else
		return (NULL);
}

bsq_class *init_bsq(int fd)
{
	bsq_class	*self = (bsq_class *)malloc(sizeof(bsq_class));
	char		len[1000];

	if (self == NULL)
		return (NULL);
	self->scan_line = &fp_scan_line;
	self->get_line = &fp_get_line;
	self->fd = fd;
	my_fgets(len, 1000, self->fd);
	self->size.height = my_atoi(len);
	if (self->size.height <= 0 || self->size.height >= 5500)
		return (NULL);
	self->map = (char **)malloc(sizeof(char *) * self->size.height + 1);
	self->sol = (int **)malloc(sizeof(int *) * self->size.height);
	if (self->map == NULL || self->sol == NULL)
		return (NULL);
	return (set_to_zero(self));
}

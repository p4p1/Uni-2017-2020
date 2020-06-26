/*
** EPITECH PROJECT, 2017
** string.c
** File description:
** <..>
*/

#include "pushswap.h"

static void add_more(pushswap_t *self)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * self->buf_siz);
	if (tmp != NULL) {
		my_strcpy(tmp, self->buffer);
		free(self->buffer);
		self->buf_siz *= 2;
		self->buffer = (char *)malloc(sizeof(char) * self->buf_siz);
		if (self->buffer == NULL)
			return;
		for (int i = 0; i < self->buf_siz; i++)
			self->buffer[i] = 0;
		my_strcpy(self->buffer, tmp);
		free(tmp);
	}
}

void add_str(char const *str, pushswap_t *self)
{
	int	i = 0;

	while (str[i] != '\0') {
		if ((self->pos + i) >= self->buf_siz) {
			add_more(self);
		}
		self->buffer[self->pos + i] = str[i];
		++i;
	}
	self->pos += i;
}

/*
** EPITECH PROJECT, 2017
** init.c
** File description:
** <..>
*/

#include "pushswap.h"

static struct gear *get_arg(int ac, char **av)
{
	struct gear	*g = (struct gear *)malloc(sizeof(struct gear));
	struct gear	*tmp = NULL;
	struct gear	*head = g;
	int		i = 0;

	if (g == NULL || ac == 1)
		return (NULL);
	while (i < ac) {
		g->value = my_atoi(av[i]);
		g->back = tmp;
		tmp = g;
		if (++i < ac) {
			g->next = (struct gear *)malloc(sizeof(struct gear));
			g = g->next;
		}
	}
	g->next = NULL;
	head->back = g;
	return (head);
}

int is_sorted(struct gear *la)
{
	while (la->next != NULL) {
		if (la->value > la->next->value)
			return (0);
		la = la->next;
	}
	return (1);
}

struct pushswap *init_pushswap(int *ac, char **av)
{
	pushswap_t	*self = (pushswap_t *)malloc(sizeof(pushswap_t));

	if (self == NULL)
		return (NULL);
	if (*ac > 2 && !my_strcmp(av[1], "-v")) {
		self->verbose = 1;
		av += 2;
		*ac -= 2;
	} else {
		self->verbose = 0;
		av += 1;
		*ac -= 1;
	}
	self->la = get_arg(*ac, av);
	self->lb = NULL;
	self->pos = 0;
	self->buf_siz = 1024;
	self->buffer = (char *)malloc(sizeof(char) * self->buf_siz);
	if (self->buffer == NULL || is_sorted(self->la))
		return (NULL);
	for (int i = 0; i < self->buf_siz; i++)
		self->buffer[i] = 0;
	return (self);
}

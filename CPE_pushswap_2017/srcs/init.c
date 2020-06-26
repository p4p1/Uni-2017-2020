/*
** EPITECH PROJECT, 2017
** init.c
** File description:
** <..>
*/

#include "pushswap.h"

static struct gear *get_arg(int ac, char **av)
{
	struct gear	*ge = (struct gear *)malloc(sizeof(struct gear));
	struct gear	*tmp = NULL;
	struct gear	*head = ge;
	int		i = 0;

	if (ge == NULL || ac == 1)
		return (NULL);
	while (i < ac) {
		ge->value = my_atoi(av[i]);
		ge->back = tmp;
		tmp = ge;
		if (++i < ac) {
			ge->next = (struct gear *)malloc(sizeof(struct gear));
			ge = ge->next;
		}
	}
	ge->next = NULL;
	head->back = ge;
	return (head);
}

int is_sorted(struct gear *la)
{
	while (la != NULL && la->next != NULL) {
		if (la->value > la->next->value)
			return (0);
		la = la->next;
	}
	return (1);
}

struct pushswap *init_buf(struct pushswap *ps)
{
	for (int i = 0; i < ps->buf_siz; i++)
		ps->buffer[i] = 0;
	return (ps);
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
	return (init_buf(self));
}

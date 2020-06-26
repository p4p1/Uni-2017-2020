/*
** EPITECH PROJECT, 2017
** revrotate.c
** File description:
** <..>
*/

#include "pushswap.h"

int rra(pushswap_t *self)
{
	struct gear	*tmp = self->la;

	if (self->la == NULL)
		return (0);
	add_str("rra ", self);
	tmp = tmp->back;
	tmp->next = self->la;
	tmp->back->next = NULL;
	self->la = tmp;
	return (0);
}

void reverse_list(pushswap_t *self)
{
	if (self->la->value >= 0) {
		while (self->la->back->value < 0) {
			rra(self);
		}
	}
}

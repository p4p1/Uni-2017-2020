/*
** EPITECH PROJECT, 2017
** rotate.c
** File description:
** <..>
*/

#include "pushswap.h"

int ra(pushswap_t *self)
{
	struct gear	*tmp = self->la;
	struct gear	*tmp2 = self->la;

	if (self->la == NULL || self->la->next == NULL)
		return (0);
	add_str("ra ", self);
	tmp2 = tmp2->next;
	tmp = tmp->back;
	tmp->next = self->la;
	tmp->next->next = NULL;
	self->la = tmp2;
	return (0);
}

/*
** EPITECH PROJECT, 2017
** put.c
** File description:
** <..>
*/

#include "pushswap.h"

int pa(pushswap_t *self)
{
	struct gear	*tmp;

	if (self->lb == NULL)
		return (0);
	add_str("pa ", self);
	if (self->lb->next)
		self->lb->next->back = self->lb->back;
	tmp = self->lb->next;
	self->lb->next = self->la;
	self->lb->back = (self->la) ? self->la->back : self->lb;
	if (self->la)
		self->la->back = self->lb;
	self->la = self->lb;
	self->lb = tmp;
	return (0);
}

int pb(pushswap_t *self)
{
	struct gear	*tmp;

	if (self->la == NULL)
		return (0);
	add_str("pb ", self);
	disp_list(self);
	if (self->la->next)
		self->la->next->back = self->la->back;
	tmp = self->la->next;
	self->la->next = self->lb;
	self->la->back = (self->lb) ? self->lb->back : self->la;
	if (self->lb)
		self->lb->back = self->la;
	self->lb = self->la;
	self->la = tmp;
	return (0);
}

void put_in_b(pushswap_t *self)
{
	while (self->lb) {
		pa(self);
	}
}

/*
** EPITECH PROJECT, 2017
** pop_stack_to_queue.c
** File description:
** pop an element form the stack and place it to the queue
*/

#include "clist.h"

void pop_stack_to_queue(struct stack **s, struct queue **q)
{
	char	*t_ch = NULL;

	if ((*s) != NULL) {
		t_ch = pop_stack(s);
		add_queue(q, t_ch);
		free(t_ch);
	}
}

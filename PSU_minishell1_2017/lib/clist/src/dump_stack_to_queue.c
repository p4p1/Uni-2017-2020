/*
** EPITECH PROJECT, 2017
** dump_stack_to_queue.c
** File description:
** dump the content of the stack to the queue
*/

#include "clist.h"

void dump_stack_to_queue(struct stack **s, struct queue **q)
{
	char	*temp_ch = 0;

	while ((*s) != NULL) {
		temp_ch = pop_stack(s);
		add_queue(q, temp_ch);
		free(temp_ch);
	}
}

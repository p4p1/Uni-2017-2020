/*
** EPITECH PROJECT, 2017
** move_queue.c
** File description:
** move to next_queue element
*/

#include "clist.h"

void move_queue(struct queue **q)
{
	struct queue	*t_q = 0;

	t_q = (*q);
	(*q) = (*q)->next;
	free(t_q->token);
	free(t_q);
}

/*
** EPITECH PROJECT, 2017
** disp_stack.c
** File description:
** display all the values that are in the queue
*/

#include "clist.h"

void disp_queue(struct queue *q)
{
	int	i = 0;

	my_putastr("\n*******QUEUE*******\n");
	if (q) {
		do {
			my_print_nbr(i++);
			my_putachar(':');
			if (q->token)
				my_putastr(q->token);
			my_putachar('\n');
			q = q->next;
		} while (q != NULL);
	} else {
		my_putastr("\nEMPTY QUEUE\n\n");
	}
	my_putastr("****END OF QUEUE*****\n");
}


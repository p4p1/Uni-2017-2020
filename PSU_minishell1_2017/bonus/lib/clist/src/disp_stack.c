/*
** EPITECH PROJECT, 2017
** disp_stack.c
** File description:
** display all the values that are on the stack
*/

#include "clist.h"

int disp_stack(struct stack *s)
{
	int	i = 0;

	my_putastr("\n*******STACK*******\n");
	if (s == 0) {
		my_putastr("\nEMPTY STACK\n\n");
		return (0);
	}
	do {
		my_print_nbr(i);
		my_putachar(':');
		if (s->token)
			my_putastr(s->token);
		my_putachar('\n');
		s = s->next;
		++i;
	} while (s != 0);
	my_putastr("****END OF STACK*****\n");
	return (0);
}


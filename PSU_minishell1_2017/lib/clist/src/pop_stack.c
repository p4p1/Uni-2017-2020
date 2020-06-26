/*
** EPITECH PROJECT, 2017
** pop_stack.c
** File description:
** pop the value that is on the top of the stack
*/

#include "clist.h"

char *pop_stack(struct stack **root)
{
	char	*temp_value = 0;
	struct stack	*tmp_addr = 0;

	if (*(root)) {
		temp_value = my_strdp((*root)->token);
		tmp_addr = *(root);
		*(root) = (*root)->next;
		free(tmp_addr->token);
		free(tmp_addr);
		return (temp_value);
	} else {
		return (0);
	}
}

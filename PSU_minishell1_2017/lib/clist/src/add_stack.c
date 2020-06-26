/*
** EPITECH PROJECT, 2017
** add_stack.c
** File description:
** add an element to the stack
*/

#include "clist.h"

void add_stack(struct stack **root, char *value)
{
	struct stack *tmp_root = (struct stack *)malloc(sizeof(struct stack));

	tmp_root->token = my_strdp(value);
	tmp_root->next = *root;
	*root = tmp_root;
}

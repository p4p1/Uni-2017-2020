/*
** EPITECH PROJECT, 2017
** get_stack_token.c
** File description:
** get a token from the stack
*/

#include "clist.h"

char get_stack_token(struct stack *s)
{
	if (s) {
		if (s->token != 0)
			return (*s->token);
	}
	return (0);
}

/*
** EPITECH PROJECT, 2017
** get.c
** File description:
** <..>
*/

#include "pushswap.h"

int get_last(struct gear *l)
{
	while (l->next != 0)
		l = l->next;
	return (l->value);
}

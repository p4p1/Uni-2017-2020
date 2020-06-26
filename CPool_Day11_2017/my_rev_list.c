/*
** EPITECH PROJECT, 2017
** my_rev_list
** File description:
** <..>
*/

#include "include/mylist.h"
#include <stdio.h>

void my_putchar(char c);

void my_rev_list(linked_list_t **begin)
{
	linked_list_t *next = 0;
	linked_list_t *prev = 0;
	linked_list_t *current = *begin;

	while (current != 0) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*begin = prev;
}


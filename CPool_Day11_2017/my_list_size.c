/*
** EPITECH PROJECT, 2017
** my_list_size
** File description:
** <..>
*/

#include "include/mylist.h"

void my_putchar(char c);

int my_list_size(linked_list_t const *begin)
{
	int	len = 0;

	while (begin->next != 0) {
		begin = begin->next;
		len++;
	}
	return (len);
}

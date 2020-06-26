/*
** EPITECH PROJECT, 2017
** my_params_to_list
** File description:
** my_parameters to list
*/

#include "include/my.h"
#include "include/mylist.h"
#include <stdlib.h>
#include <stdio.h>

void my_putchar(char c);

linked_list_t *my_params_to_list(int ac, char * const *av)
{
	int	i = 0;
	linked_list_t	*head = malloc(sizeof(linked_list_t));
	linked_list_t	*tmp = head;

	while (i <= ac-1) {
		tmp->data = av[(ac - 1) - i++];
		tmp->next = malloc(sizeof(linked_list_t));
		tmp = tmp->next;
	}
	tmp->next = 0;
	return (head);
}


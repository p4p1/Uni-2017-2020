/*
** EPITECH PROJECT, 2018
** simple_list3.c
** File description:
** <..>
*/

#include "simple_list.h"
#include <stdlib.h>

double list_get_elem_at_back(list_t list)
{
    if (list == NULL)
        return (0);
    while (list->next)
        list = list->next;
    return (list->value);
}

double list_get_elem_at_position(list_t list, unsigned int position)
{
    if (list == NULL)
        return (0);
    if (position == 0)
        return (list_get_elem_at_front(list));
    while (list->next && position--)
        list = list->next;
    if (position > 0)
        return (0);
    return (list->value);
}

node_t *list_get_first_node_with_value(list_t list, double value)
{
    while (list && list->value == value)
        list = list->next;
    return (list);
}

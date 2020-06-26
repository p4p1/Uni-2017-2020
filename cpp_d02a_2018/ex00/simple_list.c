/*
** EPITECH PROJECT, 2018
** simple_list.c
** File description:
** <..>
*/

#include "simple_list.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int list_get_size(list_t list)
{
    int no = 0;

    while (list) {
        ++no;
        list = list->next;
    }
    return (no);
}

bool_t list_is_empty(list_t list)
{
    if (!list)
        return (TRUE);
    return (FALSE);
}

void list_dump(list_t list)
{
    while (list) {
        printf("%f\n", list->value);
        list = list->next;
    }
}

bool_t list_add_elem_at_front(list_t *front_ptr, double elem)
{
    list_t  el = malloc(sizeof(node_t));

    if (el == NULL || front_ptr == NULL)
        return (FALSE);
    el->value = elem;
    el->next = *front_ptr;
    *front_ptr = el;
    return (TRUE);
}

bool_t list_add_elem_at_back(list_t *front_ptr, double elem)
{
    list_t  el = malloc(sizeof(node_t));
    list_t  current = NULL;

    if (el == NULL || front_ptr == NULL)
        return (FALSE);
    if (*front_ptr) {
        current = *front_ptr;
        el->value = elem;
        el->next = NULL;
        while (current->next)
            current = current->next;
       current->next = el;
    } else {
        el->value = elem;
        el->next = NULL;
        *front_ptr = el;
    }
}

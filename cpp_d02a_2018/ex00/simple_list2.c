/*
** EPITECH PROJECT, 2018
** simple_list2.c
** File description:
** <..>
*/

#include "simple_list.h"
#include <stdlib.h>
#include <stdio.h>

bool_t list_add_elem_at_position(list_t *front_ptr, double elem, unsigned int
        position)
{
    list_t  el = malloc(sizeof(node_t));
    list_t  current = NULL;
    list_t  nxt = NULL;

    if (el == NULL || front_ptr == NULL || *front_ptr == NULL)
        return (FALSE);
    if (position == 0)
        list_add_elem_at_front(front_ptr, elem);
    nxt = *front_ptr;
    current = (*front_ptr)->next;
    while (position-- != 0 && current) {
        current = current->next;
        nxt = nxt->next;
    }
    if (position != 0)
        return (FALSE);
    nxt->next = el;
    el->next = current;
    el->value = elem;
    return (TRUE);
}

bool_t list_del_elem_at_front(list_t *front_ptr)
{
    list_t  elem = NULL;

    if (front_ptr == NULL || *front_ptr == NULL)
        return (FALSE);
    elem = (*front_ptr)->next;
    free(*front_ptr);
    *front_ptr = elem;
    return (TRUE);
}

bool_t list_del_elem_at_back(list_t *front_ptr)
{
    list_t  elem = NULL;
    list_t  tmp = NULL;

    if (front_ptr == NULL || *front_ptr == NULL)
        return (FALSE);
    elem = *front_ptr;
    tmp = (*front_ptr)->next;
    while (tmp) {
        elem = elem->next;
        tmp = tmp->next;
    }
    free(tmp);
    elem->next = NULL;
    return (TRUE);
}

bool_t list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    list_t  elem = NULL;
    list_t  tmp = NULL;

    if (front_ptr == NULL || *front_ptr == NULL)
        return (FALSE);
    if (position == 0)
        list_del_elem_at_front(front_ptr);
    elem = *front_ptr;
    tmp = (*front_ptr)->next;
    while (tmp && position--) {
        elem = elem->next;
        tmp = tmp->next;
    }
    if (position > 0)
        return (FALSE);
    elem->next = tmp->next;
    free(tmp);
    return (TRUE);
}

double list_get_elem_at_front(list_t list)
{
    if (list == NULL)
        return (0);
    return (list->value);
}

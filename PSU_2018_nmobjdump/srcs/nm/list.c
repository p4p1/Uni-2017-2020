/*
** EPITECH PROJECT, 2018
** list.c
** File description:
** <..>
*/

#include "nm.h"

list_t *add_to_list(Elf64_Sym *token)
{
    static list_t   *list = NULL;
    list_t          *tmp = NULL;

    if (list == NULL) {
        list = malloc(sizeof(list));
        if (list == NULL)
            return (NULL);
        list->next = NULL;
        list->sym = token;
    } else {
        tmp = list;
        while (tmp->next != NULL)
            tmp  = tmp->next;
        tmp->next = malloc(sizeof(list));
        if (tmp->next == NULL)
            return (NULL);
        tmp->next->sym = token;
        tmp->next->next = NULL;
    }
    return (list);
}

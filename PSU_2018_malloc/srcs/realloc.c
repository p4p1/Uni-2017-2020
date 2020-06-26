/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** realloc
*/

#include "my_malloc.h"

static void cpy_mem(void *ptr, void *new, alloc_t *list, size_t size)
{
        if (list->size >= size)
                memcpy(new, ptr, size);
        else
                memcpy(new, ptr, list->size);
}

void *realloc(void *ptr, size_t size)
{
    void *new = NULL;
    alloc_t *tmp = alloc_list;

    if (!ptr)
        return(malloc(size));
    if (size == 0 && ptr) {
        free(ptr);
        return (NULL);
    }
    while (tmp != NULL) {
        if (tmp->current == ptr)
            break;
        tmp = tmp->next;
    }
    if (!tmp)
        return (NULL);
    new = malloc(tmp->size);
    cpy_mem(ptr, new, tmp, size);
    free(ptr);
    return (new);
}

/*
** EPITECH PROJECT, 2018
** free.c
** File description:
** <..>
*/

#include "my_malloc.h"
#include <stdio.h>
#include <stdint.h>

static void remove_last_ptr(alloc_t *pal)
{
    if (pal->next == NULL) {
        if (pal->prev)
            pal->prev->next = NULL;
        sbrk((pal->size * -1));
    }
}

void free(void *ptr)
{
    alloc_t	*pal = (alloc_t *)(((uintptr_t)ptr -
        (uintptr_t)offsetof(alloc_t, current)) - (uintptr_t) 2280);

    if (ptr) {
        pal->is_free = 1;
        remove_last_ptr(pal);
    }
}

/*
** EPITECH PROJECT, 2018
** malloc.c
** File description:
** <..>
*/

#include <stdio.h>
#include "my_malloc.h"

static void set_alloc_list(alloc_t *ptr)
{
    if (alloc_list == NULL) {
        alloc_list = ptr;
        alloc_list_start = alloc_list;
        return;
    }
    while (alloc_list->next && alloc_list->size < ptr->size)
        alloc_list = alloc_list->next;
    while (alloc_list->prev && alloc_list->size > ptr->size)
        alloc_list = alloc_list->prev;
    if (alloc_list->size < ptr->size) {
        add_after_current(ptr);
    } else {
        add_before_current(ptr);
    }
}

static alloc_t *set_alloc_ptr(alloc_t *alloc_ptr, size_t size, int page_no)
{
    alloc_ptr->size = size;
    alloc_ptr->free_size = (PAGE_SIZE * page_no) - size;
    alloc_ptr->is_free = 0;
    alloc_ptr->current = alloc_ptr + sizeof(alloc_t);
    alloc_ptr->next = NULL;
    alloc_ptr->prev = NULL;
    set_alloc_list(alloc_ptr);
    return (alloc_ptr);
}

static void *find_all_ready_free(size_t size)
{
    alloc_t *tmp = alloc_list;

    if (alloc_list == NULL)
        return (NULL);
    while (tmp && tmp->next && tmp->size < size) {
        tmp = tmp->next;
    }
    while (tmp && tmp->prev && tmp->size > size) {
        tmp = tmp->prev;
    }
    if (tmp->is_free) {
        return (tmp);
    }
    return (NULL);
}

void *malloc(size_t size)
{
    alloc_t *alloc_ptr = NULL;
    void *ptr = NULL;
    int pg_no = 1;

    if ((size / PAGE_SIZE) > 0)
        pg_no = (size / PAGE_SIZE) + 1;
    if ((alloc_ptr = find_all_ready_free(size)) == NULL) {
        if ((alloc_ptr = sbrk((pg_no * PAGE_SIZE) + sizeof(alloc_t))) ==
                (void *)-1)
            return (NULL);
        alloc_ptr = set_alloc_ptr(alloc_ptr, size, pg_no);
        ptr = alloc_ptr + sizeof(alloc_t);
    }
    return (ptr);
}

/*
** EPITECH PROJECT, 2018
** list.c
** File description:
** <..>
*/

#include "my_malloc.h"

void disp_node(alloc_t *ptr)
{
    my_putstr("NODE ");
    my_putnbr_base_local((unsigned long)ptr, "0123456789abcdef");
    my_putstr(" INFORMATION\n");
    my_putstr("ptr->size: ");
    my_putnbr_base_local((unsigned long)ptr->size, "0123456789");
    my_putchar('\n');
    my_putstr("ptr->free_size: ");
    my_putnbr_base_local((unsigned long)ptr->free_size, "0123456789");
    my_putchar('\n');
    my_putstr("ptr->is_free: ");
    my_putnbr_base_local((unsigned long)ptr->is_free, "0123456789");
    my_putchar('\n');
    my_putstr("ptr->next: ");
    if (ptr->prev)
        my_putnbr_base_local((unsigned long)ptr->next, "0123456789abcdef");
    else
        my_putstr("(null)");
    my_putchar('\n');
    my_putstr("ptr->prev: ");
    if (ptr->prev)
        my_putnbr_base_local((unsigned long)ptr->prev, "0123456789abcdef");
    else
        my_putstr("(null)");
    my_putchar('\n');
}

void add_before_current(alloc_t *ptr)
{
    ptr->prev = alloc_list->prev;
    if (alloc_list->prev)
        alloc_list->prev->next = ptr;
    ptr->next = alloc_list;
    alloc_list->prev = ptr;
    alloc_list = ptr;
}

void add_after_current(alloc_t *ptr)
{
    ptr->next = alloc_list->next;
    if (alloc_list->next)
        alloc_list->next->prev = ptr;
    ptr->prev = alloc_list;
    alloc_list->next = ptr;
    alloc_list = ptr;
}

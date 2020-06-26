/*
** EPITECH PROJECT, 2018
** ptr_tricks.c
** File description:
** <..>
*/

#include "ptr_tricks.h"
#include <stdio.h>
#include <stddef.h>

int get_array_nb_elem(const int *ptr1, const int *ptr2)
{
    int no = 0;

    if (ptr1 == NULL || ptr2 == NULL)
        return (0);
    while (ptr1++ == ptr2)
        no++;
    return (no);
}

whatever_t *get_struct_ptr(const int *member_ptr)
{
    whatever_t  *ptr = (whatever_t *)((long int)member_ptr - (long int)offsetof(whatever_t, member));

    return (ptr);
}

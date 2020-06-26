/*
** EPITECH PROJECT, 2018
** sample_main_2.c
** File description:
** <..>
*/

#include "ptr_tricks.h"
#include <stdio.h>

whatever_t *get_struct_ptr(const int *member_ptr);

int main(void)
{
    whatever_t  test;
    whatever_t  *ptr = get_struct_ptr(&test.member);

    if (ptr == &test)
        printf("It works!\n");
}

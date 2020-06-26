/*
** EPITECH PROJECT, 2018
** add_mul.c
** File description:
** <..>
*/

#include <stdlib.h>

void add_mul_4param(int first, int second, int *sum, int *product)
{
    if (sum != NULL)
        *sum = first + second;
    if (product != NULL)
        *product = first * second;
}

void add_mul_2param(int *first, int *second)
{
    int first_save = 0;
    int second_save = 0;

    if (first != NULL && second != NULL) {
        first_save = *first;
        second_save = *second;
        *first = first_save + second_save;
        *second = first_save * second_save;
    }
}

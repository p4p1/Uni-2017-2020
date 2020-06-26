/*
** EPITECH PROJECT, 2018
** div.c
** File description:
** <..>
*/

#include "castmania.h"
#include <stdlib.h>

int integer_div(int a, int b)
{
    if (b == 0)
        return (0);
    return (a / b);
}

float decimale_div(int a, int b)
{
    if (b == 0)
        return (0);
    return ((float) a / (float) b);
}

void exec_div(division_t *operation)
{
    integer_op_t    *integer_op = NULL;
    decimale_op_t    *decimale_op = NULL;

    if (operation == NULL)
        return;
    if (operation->div_type == INTEGER) {
        integer_op = operation->div_op;
        integer_op->res = integer_div(integer_op->a, integer_op->b);
    } else if (operation->div_type == DECIMALE) {
        decimale_op = operation->div_op;
        decimale_op->res = decimale_div(decimale_op->a, decimale_op->b);
    }
}

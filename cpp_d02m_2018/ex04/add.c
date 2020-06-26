/*
** EPITECH PROJECT, 2018
** add.c
** File description:
** <..>
*/

#include "castmania.h"
#include <stdlib.h>

int normal_add(int a, int b)
{
    return (a + b);
}

int absolute_add(int a, int b)
{
    if (a < 0)
        a *= -1;
    if (b < 0)
        b *= -1;
    return (a + b);
}

void exec_add(addition_t *operation)
{
    if (operation == NULL)
        return;
    if (operation->add_type == NORMAL) {
        operation->add_op.res = normal_add(operation->add_op.a,
                operation->add_op.b);
    } else if (operation->add_type == ABSOLUTE) {
        operation->add_op.res = absolute_add(operation->add_op.a,
                operation->add_op.b);
    }
}

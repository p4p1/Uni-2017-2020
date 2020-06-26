/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** <..>
*/

#include <stdlib.h>
#include <stdio.h>
#include "ex_6.h"

int main(void)
{
    foo_t foo;
    short l;

    foo.bar = 0;
    foo.foo.foo = 0xCAFE;
    printf("%d\n", sizeof(l));
    printf("%d\n", sizeof(foo) == sizeof(foo.foo));
    printf("%d\n", sizeof(foo.foo.bar.foo) == sizeof(foo.foo.foo));
    printf("%d\n", sizeof(foo.bar) == 2 * sizeof(foo.foo.bar));
    printf("%d\n", sizeof(foo.foo.foo) == sizeof(foo.foo.bar.bar));
    printf("%08X\n", foo.bar);
    return (0);
}

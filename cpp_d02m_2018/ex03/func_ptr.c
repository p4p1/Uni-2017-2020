/*
** EPITECH PROJECT, 2018
** func_ptr.c
** File description:
** <..>
*/

#include <stdio.h>
#include <string.h>

#include "func_ptr.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    for (int i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void print_upper(const char *str)
{
    for (int i = 0; i < strlen(str); i++) {
        printf("%c", (str[i] > 96 && str[i] < 123) ? str[i] - 32 : str[i]);
    }
    printf("\n");
}

void print_42(const char *str)
{
    (void) str;
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*fp[])(const char *str) = { print_normal, print_reverse,
        print_upper, print_42 };

    if (action >= PRINT_NORMAL && action <= PRINT_42) {
        fp[action](str);
    }
}

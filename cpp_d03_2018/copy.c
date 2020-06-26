/*
** EPITECH PROJECT, 2018
** copy.c
** File description:
** <..>
*/

#include <string.h>
#include <stdio.h>

#include "string.h"

size_t ptr_copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t i = 0;

    if (this == NULL || s == NULL || n == 0 || pos > strlen(this->str))
        return (0);
    for (i = 0; i < n; i++) {
        s[i] = this->str[i + pos];
    }
    return (i);
}

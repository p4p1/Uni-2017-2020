/*
** EPITECH PROJECT, 2018
** compare.c
** File description:
** <..>
*/

#include <stdio.h>
#include <string.h>

#include "string.h"

int ptr_compare_s(const string_t *this, const string_t *str)
{
    if (this == NULL || str == NULL || this->str == NULL || str->str == NULL)
        return (-1);
    return (strcmp(this->str, str->str));
}

int ptr_compare_c(const string_t *this, const char *str)
{
    if (this == NULL || str == NULL || this->str == NULL)
        return (-1);
    return (strcmp(this->str, str));
}

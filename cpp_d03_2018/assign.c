/*
** EPITECH PROJECT, 2018
** assign.c
** File description:
** <..>
*/

#include <string.h>
#include <stdlib.h>

#include "string.h"

void ptr_assign_s(string_t *this, const string_t *str)
{
    if (this != NULL && str != NULL)
        if (str->str != NULL)
            this->str = strdup(str->str);
}

void ptr_assign_c(string_t *this, const char *s)
{
    if (this != NULL && s != NULL)
        this->str = strdup(s);
}

/*
** EPITECH PROJECT, 2018
** empty.c
** File description:
** <..>
*/

#include <string.h>

#include "string.h"

int ptr_empty(const string_t *this)
{
    if (this == NULL)
        return (1);
    if (this->str == NULL)
        return (1);
    if (strlen(this->str) == 0)
        return (1);
    return (0);
}

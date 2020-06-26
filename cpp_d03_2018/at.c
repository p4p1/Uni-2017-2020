/*
** EPITECH PROJECT, 2018
** at.c
** File description:
** <..>
*/

#include <stdlib.h>
#include <string.h>

#include "string.h"

char ptr_at(const string_t *this, size_t pos)
{
    if (pos >= strlen(this->str))
        return (-1);
    return (this->str[pos]);
}

/*
** EPITECH PROJECT, 2018
** size.c
** File description:
** <..>
*/

#include <stdlib.h>
#include <string.h>

#include "string.h"

int ptr_size(const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return (-1);
    return (strlen(this->str));
}

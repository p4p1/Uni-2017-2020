/*
** EPITECH PROJECT, 2018
** c_str.c
** File description:
** <..>
*/

#include <stdlib.h>

#include "string.h"

const char *ptr_c_str(const string_t *this)
{
    if (this == NULL)
        return (NULL);
    return (this->str);
}

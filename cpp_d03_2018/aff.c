/*
** EPITECH PROJECT, 2018
** add.c
** File description:
** <..>
*/

#include <stdio.h>

#include "string.h"

void ptr_aff(const string_t *this)
{
    if (this && this->str)
        printf("%s", this->str);
}

/*
** EPITECH PROJECT, 2018
** clear.c
** File description:
** <..>
*/

#include <stdlib.h>
#include <string.h>

#include "string.h"

void ptr_clear(string_t *this)
{
    int size = 0;
    if (this != NULL && this->str != NULL) {
        size = strlen(this->str);
        for (int i = 0; i < size; i++)
            this->str[i] = 0;
    }
}

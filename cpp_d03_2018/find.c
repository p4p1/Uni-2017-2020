/*
** EPITECH PROJECT, 2018
** find.c
** File description:
** <..>
*/

#include <stdlib.h>
#include <string.h>

#include "string.h"

int ptr_find_s(const string_t *this, const string_t *str, size_t pos)
{
    unsigned int    i = 0;
    char    *st = NULL;
    char    *st2 = NULL;

    if (this == NULL || str == NULL || this->str == NULL ||
            pos > strlen(this->str) || str->str == NULL)
        return (-1);
    st2 = this->str;
    st = strstr(this->str + pos, str->str);
    for (i = 0; st2 != st; i++) {
        ++st2;
    }
    if (i == strlen(this->str))
        return (-1);
    return (i);
}

int ptr_find_c(const string_t *this, const char *str, size_t pos)
{
    unsigned int    i = 0;
    char    *st = NULL;
    char    *st2 = NULL;

    if (this == NULL || str == NULL || this->str == NULL ||
            pos > strlen(this->str))
        return (-1);
    st2 = this->str;
    st = strstr(this->str + pos, str);
    for (i = 0; st2 != st; i++) {
        ++st2;
    }
    if (i == strlen(this->str))
        return (-1);
    return (i);
}

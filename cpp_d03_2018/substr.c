/*
** EPITECH PROJECT, 2018
** substr.c
** File description:
** <..>
*/

#include <stdlib.h>
#include <string.h>

#include "string.h"

static int calculate_size(int offset, int length)
{
    if (length < 0)
        length *= -1;
    if (offset < 0)
        offset *= -1;
    return (length - offset);
}

static int get_offset(int offset, int length, char *str)
{
    if (offset < 0 && length < 0) {
        return ((length * -1) - (offset * -1));
    }
    if (offset < 0) {
        return (strlen(str) + offset);
    }
    if (length < 0) {
        return (offset);
    }
    return (length - offset);
}

static int mstrlen(const char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

string_t *ptr_substr(const string_t *this, int offset, int length)
{
    string_t    *sub = malloc(sizeof(string_t));
    int     size = calculate_size(offset, length);
    int     off = get_offset(offset, length, this->str);

    if (this == NULL || sub == NULL)
        return (NULL);
    sub->str = malloc(sizeof(char) * size + 1);
    if (sub->str == NULL)
        return (NULL);
    for (int i = 0; i < size; i++) {
        if (length < 0)
            sub->str[i] = this->str[off - i];
        else
            sub->str[i] = this->str[i + off];
        if ((length > 0) && ((i + off) > mstrlen(this->str) || (i + off) < 0))
            break;
        if ((length < 0) && ((i - off) > mstrlen(this->str) || (i - off) < 0))
            break;
    }
    sub->str[size] = '\0';
    return (sub);
}

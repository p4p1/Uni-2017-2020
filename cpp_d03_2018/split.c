/*
** EPITECH PROJECT, 2018
** split.c
** File description:
** <..>
*/

#include <stdlib.h>
#include <string.h>

#include "string.h"

static int  to_next(char *str, char separator)
{
    int pos = 0;

    while (str[pos] != separator && str[pos])
        pos++;
    return (pos);
}

static int word_no(char *str, char separator)
{
    int no = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == separator)
            ++no;
    return (no + 1);
}

string_t **ptr_split_s(const string_t *this, char separator)
{
    int     i = 0;
    string_t **tmp = NULL;
    char    *str = (this) ? this->str : NULL;

    if (this == NULL || this->str == NULL)
        return (NULL);
    tmp = malloc(sizeof(string_t *) * (word_no(this->str, separator) + 1));
    if (tmp == NULL)
        return (NULL);
    for (i = 0; i < word_no(this->str, separator); i++) {
        tmp[i] = malloc(sizeof(string_t));
        if (tmp[i] == NULL)
            return (NULL);
        tmp[i]->str = strndup(str, to_next(str, separator));
        if (tmp[i] == NULL)
            return (NULL);
        str += to_next(str, separator) + 1;
    }
    tmp[i] = NULL;
    return (tmp);
}

char **ptr_split_c(const string_t *this, char separator)
{
    int     i = 0;
    char    **tmp = NULL;
    char    *str = (this) ? this->str : NULL;

    if (this == NULL || this->str == NULL)
        return (NULL);
    tmp = malloc(sizeof(char *) * (word_no(this->str, separator) + 1));
    if (tmp == NULL)
        return (NULL);
    for (i = 0; i < word_no(this->str, separator); i++) {
        tmp[i] = strndup(str, to_next(str, separator));
        if (tmp[i] == NULL)
            return (NULL);
        str += to_next(str, separator) + 1;
    }
    tmp[i] = NULL;
    return (tmp);
}

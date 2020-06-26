/*
** EPITECH PROJECT, 2018
** join.c
** File description:
** <..>
*/

#include <stdlib.h>
#include <string.h>

#include "string.h"

static int get_sie_tab(const char * const *tab)
{
    int sz = 0;

    for (int i = 0; tab[i]; i++) {
        sz += strlen(tab[i]);
        ++sz;
    }
    return (sz);
}

static int get_sie_struct_tab(const string_t * const *tab)
{
    int sz = 0;

    for (int i = 0; tab[i]; i++) {
        sz += strlen(tab[i]->str);
        ++sz;
    }
    return (sz);
}

void ptr_join_c(string_t *this, char delim, const char * const * tab)
{
    char    *str = NULL;
    int     size = 0;
    int     i = 0;

    if (this == NULL || tab == NULL)
        return;
    size = get_sie_tab(tab);
    str = malloc(sizeof(char) * size);
    if (str == NULL)
        return;
    memset(str, 0, size);
    for (i = 0; tab[i]; i++) {
        str = strcat(str, tab[i]);
        str[strlen(tab[i])] = delim;
    }
    str[size - 1] = '\0';
    this->str = str;
}

void ptr_join_s(string_t *this, char delim, const string_t * const * tab)
{
    char    *str = NULL;
    int     size = 0;
    int     i = 0;

    if (this == NULL || tab == NULL)
        return;
    size = get_sie_struct_tab(tab);
    str = malloc(sizeof(char) * size);
    if (str == NULL)
        return;
    memset(str, 0, size);
    for (i = 0; tab[i]; i++) {
        str = strcat(str, tab[i]->str);
        str[strlen(tab[i]->str)] = delim;
    }
    str[size - 1] = '\0';
    this->str = str;
}

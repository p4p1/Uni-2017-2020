/*
** EPITECH PROJECT, 2018
** insert.c
** File description:
** <..>
*/

#include <stdlib.h>
#include <string.h>

#include "string.h"

void ptr_insert_c(string_t *this, size_t pos, const char *str)
{
    char    *new_str = NULL;
    unsigned int    i = 0;
    unsigned int    j = 0;
    unsigned int    inc = 0;

    if (this == NULL || this->str == NULL || str == NULL)
        return;
    if (pos > strlen(this->str))
        this->append_c(this, str);
    new_str = malloc(sizeof(char) * (strlen(this->str) + strlen(str) + 1));
    if (new_str == NULL)
        return;
    for (i = 0; i < pos; i++, inc++)
        new_str[i] = this->str[inc];
    for (j = 0; j < strlen(str); j++)
        new_str[i++] = str[j];
    for (; inc < strlen(this->str); inc++)
        new_str[i++] = this->str[inc];
    new_str[i] = '\0';
    free(this->str);
    this->str = new_str;
}

void ptr_insert_s(string_t *this, size_t pos, const string_t *str)
{
    char    *new_str = NULL;
    unsigned int    i = 0;
    unsigned int    j = 0;
    unsigned int    inc = 0;

    if (this == NULL || this->str == NULL || str == NULL || str->str == NULL)
        return;
    if (pos > strlen(this->str))
        this->append_s(this, str);
    new_str = malloc(sizeof(char) * (strlen(this->str) + strlen(str->str) + 1));
    if (new_str == NULL)
        return;
    for (i = 0; i < pos; i++, inc++)
        new_str[i] = this->str[inc];
    for (j = 0; j < strlen(str->str); j++)
        new_str[i++] = str->str[j];
    for (; inc < strlen(this->str); inc++)
        new_str[i++] = this->str[inc];
    new_str[i] = '\0';
    free(this->str);
    this->str = new_str;
}

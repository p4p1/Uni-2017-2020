/*
** EPITECH PROJECT, 2018
** append.c
** File description:
** <..>
*/

#include <stdlib.h>
#include <string.h>

#include "string.h"

void ptr_append_s(string_t *this, const string_t *ap)
{
    int size = 0;
    char    *tmp = NULL;

    if (this == NULL || ap == NULL || this->str == NULL || ap->str == NULL)
        return;
    size = strlen(this->str) + strlen(ap->str);
    tmp = malloc(sizeof(char) * size + 1);
    strcpy(tmp, this->str);
    strcat(tmp, ap->str);
    free(this->str);
    this->str = tmp;
}

void ptr_append_c(string_t *this, const char *ap)
{
    int size = 0;
    char    *tmp = NULL;

    if (this == NULL || ap == NULL || this->str == NULL || ap == NULL)
        return;
    size = strlen(this->str) + strlen(ap);
    tmp = malloc(sizeof(char) * size + 1);
    strcpy(tmp, this->str);
    strcat(tmp, ap);
    free(this->str);
    this->str = tmp;
}

/*
** EPITECH PROJECT, 2018
** mem_ptr.c
** File description:
** <..>
*/

#include <stdlib.h>
#include <string.h>

#include "mem_ptr.h"

void add_str(const char *str1, const char *str2, char **res)
{
    int     size = 0;
    char    *ptr = NULL;
    int     j = 0;

    if (str1 != NULL && str2 != NULL) {
        size = strlen(str1) + strlen(str2) + 1;
        ptr = malloc(sizeof(char) * size);
        for (int i = 0; i < strlen(str1); i++)
            ptr[j++] = str1[i];
        for (int i = 0; i < strlen(str2); i++)
            ptr[j++] = str2[i];
        ptr[j] = '\0';
        *res = ptr;
    }
}

void add_str_struct(str_op_t *str_op)
{
    int     size = 0;
    char    *ptr = NULL;
    int     j = 0;

    if (str_op != NULL && str_op->str1 != NULL && str_op->str2 != NULL) {
        size = strlen(str_op->str1) + strlen(str_op->str2) + 1;
        ptr = malloc(sizeof(char) * size);
        for (int i = 0; i < strlen(str_op->str1); i++)
            ptr[j++] = str_op->str1[i];
        for (int i = 0; i < strlen(str_op->str2); i++)
            ptr[j++] = str_op->str2[i];
        ptr[j] = '\0';
        str_op->res = ptr;
    }
}

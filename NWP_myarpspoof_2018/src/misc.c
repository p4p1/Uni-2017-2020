/*
** EPITECH PROJECT, 2018
** misc.c
** File description:
** <..>
*/

#include "myarpspoof.h"

unsigned char *ustrndup(unsigned char *src, int size)
{
    unsigned char   *tmp = malloc(sizeof(unsigned char) * size);

    if (tmp == NULL)
        return (tmp);
    for (int i = 0; i < size; i++)
        tmp[i] = src[i];
    return(tmp);
}

/*
** EPITECH PROJECT, 2018
** tab_to_2dtab.c
** File description:
** <..>
*/

#include <stdio.h>
#include <stdlib.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int **dtab = NULL;
    int inc = 0;

    if (tab == NULL)
        return;
    dtab = malloc(sizeof(int *) * length);
    if (dtab == NULL)
        return;
    for (int i = 0; i < length; i++) {
        dtab[i] = malloc(sizeof(int) * width);
        if (dtab[i] == NULL)
            return;
    }
    for (int i = 0; i < length; i++)
        for (int j = 0; j < width; j++)
            dtab[i][j] = tab[inc++];
    *res = dtab;
}

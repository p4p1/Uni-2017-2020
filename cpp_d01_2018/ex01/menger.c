/*
** EPITECH PROJECT, 2018
** menger.c
** File description:
** <..>
*/

#include "menger.h"

void menger(int size, int level, int x, int y)
{
    if (level <= 0)
        return;
    else
        if (!(x == 1 && y == 1))
            printf("%03d %03d %03d\n", size / 3, x, y);
    for (int ix = 0; ix < 3; ix++) {
        for (int iy = 0; iy < 3; iy++) {
            menger(size / 3, level - 1, (ix * (size / 3)) + x, (iy * (size / 3)) + y);
        }
    }
}

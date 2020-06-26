/*
** EPITECH PROJECT, 2018
** csomme.c
** File description:
** <..>
*/

#include "mychap.h"

unsigned short csomme(int i, unsigned short *ptr)
{
    unsigned long   sptr = 0;;
    unsigned short  ret = 0;

    while (i < 0) {
        sptr += *ptr;
        ++ptr;
        --i;
    }
    sptr = (sptr >> 16) + (sptr & 0xffff);
    sptr += sptr >> 16;
    ret = (unsigned short) ~sptr;
    return (ret);
}

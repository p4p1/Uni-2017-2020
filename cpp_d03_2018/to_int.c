/*
** EPITECH PROJECT, 2018
** to_int.c
** File description:
** <..>
*/

#include "string.h"

int ptr_to_int(const string_t *this)
{
    long long int   no = 0;
    int     neg = 1;
    char    *nptr = NULL;

    if (this == NULL || this->str == NULL)
        return (0);
    nptr = this->str;
    if (*nptr == '-')
        neg = ',' - *nptr++;
    while (*nptr != '\0') {
        if (*nptr <= '9' && *nptr >= '0') {
            no = (*nptr - '0') + (no * 10);
        } else {
            break;
        }
        nptr++;
    }
    no *= neg;
    if (no > 2147483647 || no < -2147483648)
        return (0);
    return (no);
}

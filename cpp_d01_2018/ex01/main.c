/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** <..>
*/

#include "menger.h"

static int my_atoi(const char *nptr)
{
    long long int   no = 0;
    int     neg = 1;

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

static int is_nt_number(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!isdigit(str[i++]))
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    int size;
    int level;

    if (ac != 3 || is_nt_number(av[1]) || is_nt_number(av[2]))
        return (84);
    size = my_atoi(av[1]);
    level = my_atoi(av[2]);
    menger(size, level, 1, 1);
    return (0);
}

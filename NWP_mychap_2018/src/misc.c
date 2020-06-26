/*
** EPITECH PROJECT, 2018
** misc.c
** File description:
** <..>
*/

#include "mychap.h"

int is_ip_or_host(char *target)
{
    int     no_of_dots = 0;
    unsigned int     i = 0;

    for (i = 0; i < strlen(target); i++) {
        if (target[i] == '.')
            no_of_dots++;
        else if (!(target[i] >= '0' && target[i] <= '9'))
            break;
    }
    if (no_of_dots == 3)
        return (1);
    return (0);
}

char *resolve_ip(char *target)
{
    struct hostent  *he;
    struct in_addr  **addr_list;

    if ((he = gethostbyname(target)) == NULL)
        return (NULL);
    addr_list = (struct in_addr **) he->h_addr_list;
    return (strdup(inet_ntoa(*addr_list[0])));
}

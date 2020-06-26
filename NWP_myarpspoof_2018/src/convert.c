/*
** EPITECH PROJECT, 2018
** convert.c
** File description:
** <..>
*/

#include "myarpspoof.h"

uint32_t get_ip_from_sockaddr(struct sockaddr    *addr)
{
    struct sockaddr_in  *j = (struct sockaddr_in *)addr;

    if (addr->sa_family == AF_INET) {
        return (j->sin_addr.s_addr);
    } else {
        return (0);
    }
}

const char *ip_sockaddr_to_string(struct sockaddr *addr)
{
    struct sockaddr_in  *j = (struct sockaddr_in *)addr;

    if (addr->sa_family == AF_INET) {
        return (inet_ntoa(j->sin_addr));
    } else {
        return (NULL);
    }
}

/*
** EPITECH PROJECT, 2018
** getothermac.c
** File description:
** <..>
*/

#include "myarpspoof.h"

unsigned char *getothermac(char *ip, char *iface, struct argument_info *arp, unsigned char *mac)
{
    uint32_t        dest = inet_addr(ip);
    uint32_t        src = inet_addr(arp->source_ip);
    int             ifacei;
    int             sock;

    if (dest == 0 || dest == 0xffffffff)
        return (NULL);
    if (arp->type == NOTHING && get_iface_info(iface, &src, (char *)mac, &ifacei)
            < 0 && bind_arp(ifacei, &sock) < 0)
        return (NULL);
    if (send_arp_who_has(sock, ifacei, mac, src, dest, arp) < 0)
        return (NULL);
    arp->sock = sock;
    if (arp->type != NOTHING)
        return (NULL);
    while (1) {
        if ((mac = read_arp(sock)) != NULL)
            return (mac);
    }
    return (NULL);
}

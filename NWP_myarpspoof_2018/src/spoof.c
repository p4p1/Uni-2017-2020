/*
** EPITECH PROJECT, 2018
** spoof.c
** File description:
** <..>
*/

#include "myarpspoof.h"

void set_ifr_name(struct ifreq *ifr, const char *if_name)
{
    size_t if_name_len = strlen(if_name);

    if (if_name_len < sizeof(ifr->ifr_name)) {
        ifr->ifr_name[if_name_len] = 0;
    }
}

void do_the_spoof(struct argument_info *arp_f, unsigned char *attack,
        unsigned char *vic, uint32_t src, uint32_t dst)
{
    struct ether_arp    resp;
    struct ifreq        ifr;

    memcpy(ifr.ifr_name, arp_f->iface, strlen(arp_f->iface));
}

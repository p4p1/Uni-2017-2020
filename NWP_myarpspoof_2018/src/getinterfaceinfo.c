/*
** EPITECH PROJECT, 2018
** getinterfaceinfo.c
** File description:
** <..>
*/

#include "myarpspoof.h"

static int get_iface_ip(int sock, char *iface, uint32_t *ip)
{
    struct ifreq    ifr;

    memset(&ifr, 0, sizeof(struct ifreq));
    strcpy(ifr.ifr_name, iface);
    if (ioctl(sock, SIOCGIFADDR, &ifr) == -1)
        return (-1);
    if ((*ip = get_ip_from_sockaddr(&ifr.ifr_addr)) == 0)
        return (-1);
    return (0);
}

int get_iface_info(char *iface, uint32_t *ip, char *mac, int *ifacei)
{
    struct ifreq    ifr;
    int             sock;

    if ((sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP))) <= 0)
        return (-1);
    if (strlen(iface) > (IFNAMSIZ - 1))
        return (-1);
    strcpy(ifr.ifr_name, iface);
    if (ioctl(sock, SIOCGIFINDEX, &ifr) == -1)
        return (-1);
    *ifacei = ifr.ifr_ifindex;
    if (ioctl(sock, SIOCGIFHWADDR, &ifr) == -1)
        return (-1);
    memcpy(mac, ifr.ifr_hwaddr.sa_data, MAC_LENGTH);
    if (get_iface_ip(sock, iface, ip) < 0)
        return (0);
    return (0);
}

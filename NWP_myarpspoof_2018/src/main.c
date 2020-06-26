/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** <..>
*/

#include "myarpspoof.h"

static int usage(int no)
{
    printf("USAGE: ./myARPspoof source_ip dest_ip iface\n");
    printf("run as root.\n");
    return (no);
}

static struct argument_info *get_arg(int ac, char **av)
{
    struct argument_info *arg = NULL;

    if (ac < 4)
        return (arg);
    if ((arg = malloc(sizeof(struct argument_info))) == NULL)
        return (NULL);
    arg->source_ip = av[1];
    arg->dest_ip = av[2];
    arg->iface = av[3];
    arg->type = NOTHING;
    if (ac == 5 && strcmp(av[4], "--printBroadcast") == 0)
        arg->type = PRINTBROADCAST;
    if (ac == 6 && strcmp(av[4], "--printSpoof") == 0) {
        arg->type = PRINTSPOOF;
        arg->mac_addr = av[5];
    }
    return (arg);
}

static unsigned char *create_mac_from_arg(char **av)
{
    unsigned char   *mac = malloc(sizeof(char) * MAC_LENGTH);

    if (mac == NULL)
        return (NULL);
    mac[0] = (unsigned char)strtol(av[5], NULL, 16);
    mac[1] = (unsigned char)strtol(av[5] + 3, NULL, 16);
    mac[2] = (unsigned char)strtol(av[5] + 6, NULL, 16);
    mac[3] = (unsigned char)strtol(av[5] + 9, NULL, 16);
    mac[4] = (unsigned char)strtol(av[5] + 12, NULL, 16);
    mac[5] = (unsigned char)strtol(av[5] + 15, NULL, 16);
    return (mac);
}

int main(int ac, char **av)
{
    struct argument_info    *arg = NULL;
    unsigned char *mac = NULL;
    unsigned char *mac_other = NULL;

    if ((arg = get_arg(ac, av)) == NULL)
        return (usage(84));
    mac = getmymac(arg->iface);
    if (arg->type != PRINTSPOOF) {
        mac_other = getothermac(arg->dest_ip, arg->iface, arg, mac);
        if (arg->type == PRINTBROADCAST)
            display_arp(arg);
    } else {
        mac_other = create_mac_from_arg(av);
    }
    if (arg->type == NOTHING)
        printf("Found victim’s MAC address: '%.2x:%.2x:%.2x:%.2x:%.2x:%.2x'\n",
                mac_other[0], mac_other[1], mac_other[2], mac_other[3],
                mac_other[4], mac_other[5]);
    (void) mac;
    return (0);
}

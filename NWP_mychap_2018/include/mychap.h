/*
** EPITECH PROJECT, 2017
** mychap.h
** File description:
** <..>
*/

#ifndef MYCHAP_H_
#define MYCHAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <getopt.h>

#include <arpa/inet.h>
#include <sys/socket.h>

#include <linux/ip.h>
#include <linux/udp.h>

#include <netdb.h>
#include <arpa/inet.h>

struct server_info {
    char            *addr;
    char            *passwd;
    unsigned int    port;
    struct ipheader *ip;
    struct udpheader    *udp;
};

struct mychap {
    struct server_info  *si;
    struct sockaddr_in  serv;
    int                 sock;
};

unsigned short csomme(int i, unsigned short *ptr);
char *resolve_ip(char *target);
int is_ip_or_host(char *target);

#endif

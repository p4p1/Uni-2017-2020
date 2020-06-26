/*
** EPITECH PROJECT, 2017
** myarpspoof.h
** File description:
** <..>
*/

#ifndef MYARPSPOOF_H_
#define MYARPSPOOF_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <sys/socket.h>
#include <asm/types.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <linux/if_arp.h>

#define PROTO_ARP 0x0806
#define ETH2_HEADER_LEN 14
#define HW_TYPE 1
#define MAC_LENGTH 6
#define IPV4_LENGTH 4
#define ARP_REQUEST 0x01
#define ARP_REPLY 0x02
#define BUF_SIZE 42

enum argument_type {
    NOTHING,
    PRINTBROADCAST,
    PRINTSPOOF
};

struct argument_info {
    char    *source_ip;
    char    *dest_ip;
    char    *iface;
    enum argument_type type;
    char    *mac_addr;
    int     sock;
    unsigned char    *broadcast;
    struct arp_header   *spoof;
};

struct arp_header {
    unsigned short hardware_type;
    unsigned short protocol_type;
    unsigned char hardware_len;
    unsigned char protocol_len;
    unsigned short opcode;
    unsigned char sender_mac[MAC_LENGTH];
    unsigned char sender_ip[IPV4_LENGTH];
    unsigned char target_mac[MAC_LENGTH];
    unsigned char target_ip[IPV4_LENGTH];
};

unsigned char *getmymac(char *iface);
uint32_t get_ip_from_sockaddr(struct sockaddr *addr);
const char *ip_sockaddr_to_string(struct sockaddr *addr);
int get_iface_info(char *iface, uint32_t *ip, char *mac, int *ifacei);
unsigned char *getothermac(char *ip, char *iface, struct argument_info *arp, unsigned char *mac);

int bind_arp(int ifnamei, int *soc);
int send_arp_who_has(int soc, int ifacei, const unsigned char *src_mac,
        uint32_t src_ip, uint32_t dst_ip, struct argument_info *arp);
unsigned char *read_arp(int sock);
void display_arp(struct argument_info *arp);
unsigned char *ustrndup(unsigned char *src, int size);

#endif

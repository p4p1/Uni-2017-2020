/*
** EPITECH PROJECT, 2018
** arp.c
** File description:
** <..>
*/

#include "myarpspoof.h"

struct sockaddr_ll *create_sockaddr_ll(int ifacei)
{
    struct sockaddr_ll  *tmp = malloc(sizeof(struct sockaddr_ll));

    if (tmp == NULL)
        return (NULL);
    tmp->sll_family = AF_PACKET;
    tmp->sll_protocol = htons(ETH_P_ARP);
    tmp->sll_ifindex = ifacei;
    tmp->sll_hatype = htons(ARPHRD_ETHER);
    tmp->sll_pkttype = (PACKET_BROADCAST);
    tmp->sll_halen = MAC_LENGTH;
    tmp->sll_addr[6] = 0x00;
    tmp->sll_addr[7] = 0x00;
    return (tmp);
}

static void create_arp_request(struct arp_header *arp_req)
{
    arp_req->hardware_type = htons(HW_TYPE);
    arp_req->protocol_type = htons(ETH_P_IP);
    arp_req->hardware_len = MAC_LENGTH;
    arp_req->protocol_len = IPV4_LENGTH;
    arp_req->opcode = htons(ARP_REQUEST);
}

int bind_arp(int ifnamei, int *soc)
{
    struct sockaddr_ll  sockll;

    if ((*soc = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP))) < 1)
        return (-1);
    memset(&sockll, 0, sizeof(struct sockaddr_ll));
    sockll.sll_family = AF_PACKET;
    sockll.sll_ifindex = ifnamei;
    if (bind(*soc, (struct sockaddr *) &sockll, sizeof(struct sockaddr_ll)) > 0)
        return (-1);
    return (0);
}

int send_arp_who_has(int soc, int ifacei, const unsigned char *src_mac,
        uint32_t src_ip, uint32_t dst_ip, struct argument_info *arp)
{
    unsigned char buffer[BUF_SIZE];
    struct sockaddr_ll  *sock_addr;
    struct ethhdr *send_req = (struct ethhdr *) buffer;
    struct arp_header *arp_req = (struct arp_header*)(buffer + ETH2_HEADER_LEN);

    memset(send_req->h_dest, 0xff, MAC_LENGTH);
    memset(arp_req->target_mac, 0xff, MAC_LENGTH);
    memcpy(send_req->h_source, src_mac, MAC_LENGTH);
    //printf("%.2x %.2x %.2x %.2x %.2x %.2x\n", src_mac[0], src_mac[1], src_mac[2], src_mac[3], src_mac[4], src_mac[5]);
    memcpy(arp_req->sender_mac, src_mac, MAC_LENGTH);
    create_arp_request(arp_req);
    send_req->h_proto = htons(ETH_P_ARP);
    memcpy(arp_req->sender_ip, &src_ip, sizeof(uint32_t));
    memcpy(arp_req->target_ip, &dst_ip, sizeof(uint32_t));
    arp->broadcast = ustrndup(buffer, BUF_SIZE);
    if (arp->type == NOTHING) {
        sock_addr = create_sockaddr_ll(ifacei);
        memcpy(sock_addr->sll_addr, src_mac, MAC_LENGTH);
        sendto(soc, buffer, 42, 0, (struct sockaddr*)&sock_addr, sizeof(sock_addr));
    }
    return (0);
}

unsigned char *read_arp(int sock)
{
    unsigned char buffer[BUF_SIZE];
    ssize_t length = recvfrom(sock, buffer, BUF_SIZE, 0, NULL, NULL);
    struct arp_header *arp_resp = (struct arp_header*)(buffer+ETH2_HEADER_LEN);

    if (length == -1)
        return (NULL);
    if (ntohs(arp_resp->opcode) != ARP_REPLY)
        return (NULL);
    return (arp_resp->sender_mac);
}

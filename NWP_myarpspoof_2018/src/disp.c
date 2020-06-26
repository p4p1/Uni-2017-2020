/*
** EPITECH PROJECT, 2018
** disp.c
** File description:
** <..>
*/

#include "myarpspoof.h"

void display_arp(struct argument_info *arp)
{
    for (int i = 0; i < BUF_SIZE; i++) {
        if (i < (BUF_SIZE - 1))
            printf("%.2x ", arp->broadcast[i]);
        else
            printf("%.2x", arp->broadcast[i]);
    }
    printf("\n");
}

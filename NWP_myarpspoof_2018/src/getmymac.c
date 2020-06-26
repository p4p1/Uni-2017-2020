/*
** EPITECH PROJECT, 2018
** getmymac.c
** File description:
** <..>
*/

#include "myarpspoof.h"

static int power(int a, int b)
{
    int res = 1;

    for (int i = 0; i < b; i++)
        res *= a;
    return (res);
}

static char to_char(char ch)
{
    if (ch >= '0' && ch <= '9')
        return (ch - '0');
    if (ch == 'A' || ch == 'a')
        return (10);
    if (ch == 'B' || ch == 'b')
        return (11);
    if (ch == 'C' || ch == 'c')
        return (12);
    if (ch == 'D' || ch == 'd')
        return (13);
    if (ch == 'E' || ch == 'e')
        return (14);
    if (ch == 'F' || ch == 'f')
        return (15);
    return (0);
}

unsigned char *getmymac(char *iface)
{
    char            *file_name = malloc(sizeof(char) * (50 + strlen(iface)));
    unsigned char   *mac = malloc(sizeof(char) * MAC_LENGTH);
    FILE            *fp;
    char            ch;
    int             z = 1;

    sprintf(file_name, "/sys/class/net/%s/address", iface);
    fp = fopen(file_name, "r");
    memset(mac, 0, MAC_LENGTH);
    for (int i = 0; i < MAC_LENGTH; i++) {
        z = 1;
        while ((ch = fgetc(fp)) != ':' && feof(fp) == 0 && z >= 0) {
            mac[i] += to_char(ch) * power(16, z--);
        }
    }
    fclose(fp);
    return (mac);
}

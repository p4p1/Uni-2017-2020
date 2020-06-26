/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** <..>
*/

#include "mychap.h"

static void usage(int no)
{
    printf("USAGE: ./mychap\n"
        "\t-t\t--target\tthe target\n"
        "\t-p\t--port\t\tthe port\n"
        "\t-P\t--password\tthe password\n");
    exit(no);
}

static int work_opt(struct server_info *si, char c)
{
    if (c == 't')
        si->addr = strdup(optarg);
    else if (c == 'p')
        si->port = atoi(optarg);
    else if (c == 'P')
        si->passwd = strdup(optarg);
    else if (c == 'h')
        usage(0);
    else
        return (-1);
    return (0);
}

static struct mychap *init_chap(struct server_info *si)
{
    struct mychap   *this = malloc(sizeof(struct server_info));
    int             val = 1;

    if (this == NULL)
        return (NULL);
    this->si = si;
    this->sock = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
    if (this->sock < 0)
        return (NULL);
    if (setsockopt(this->sock, IPPROTO_IP, IP_HDRINCL, &val, sizeof(val)) < 0)
        return (NULL);
    this->serv.sin_family = AF_INET;
    this->serv.sin_port = htons(this->si->port);
    this->serv.sin_addr.s_addr = inet_addr(this->si->addr);
    return (this);
}

int main(int argc, char **argv)
{
    int c;
    int opt_ind;
    char    *ip = NULL;
    struct server_info  si = { NULL, NULL, 0, NULL, NULL };
    struct mychap       *this = NULL;
    struct option l_opt[] = { {"target", required_argument, 0, 't'}, {"port",
        required_argument, 0, 'p'}, {"password", required_argument, 0, 'P'},
                  {0, 0, 0, 0} };

    while ((c = getopt_long(argc, argv, "ht:p:P:", l_opt, &opt_ind)) != -1)
        if (work_opt(&si, c) == -1)
            return (84);
    if ((si.addr == NULL || si.port == 0 || si.passwd == NULL) &&
            (this = init_chap(&si)) == NULL)
        usage(84);
    if (!is_ip_or_host(si.addr)) {
        ip = resolve_ip(si.addr);
        if (ip == NULL)
            printf("No such hostname: %s\n", si.addr);
    }
    return (0);
}

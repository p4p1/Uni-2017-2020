/*
** EPITECH PROJECT, 2018
** network.c
** File description:
** <..>
*/

#include "myftp.h"

int wait_client(struct server_information *si)
{
    int cs;
    int client_sock = 0;

    cs = sizeof(struct sockaddr_in);
    client_sock = accept(si->server_sock, (struct sockaddr *)&si->client[0],
            (socklen_t*)&cs);
    if (client_sock < 0)
        return (-1);
    for (int i = 0; i < CLIENT_NUM; i++) {
        if (si->client_sock[i] == 0) {
            si->client_sock[i] = client_sock;
            send_buffer(si, "220 (vsFTPd 1.0.0)\n", i);
            break;
        }
    }
    return (0);
}

char *read_buffer(struct server_information *si, int cli_no)
{
    int n = 0;
    int i = 0;
    char    *ptr = malloc(sizeof(char) * BUFSIZ);

    n = read(si->client_sock[cli_no], ptr, BUFSIZ);
    if (n <= 0) {
        free(ptr);
        return (NULL);
    }
    ptr[n] = '\0';
    for (i = 0; ptr[i]; i++) {
        if (ptr[i] == '\n')
            ptr[i] = '\0';
        if (ptr[i] < 0)
            break;
    }
    if (ptr[i] < 0) {
        free(ptr);
        return (NULL);
    }
    return (ptr);
}

int send_buffer(struct server_information *si, char *buffer, int cli_no)
{
    char    *buf = NULL;
    int     n = 0;

    if (buffer == NULL) {
        buf = malloc(sizeof(char) * BUFSIZ);
        if (buf == NULL)
            return (-1);
        buf = fgets(buf, BUFSIZ, stdin);
        if (buf == NULL)
            return (-1);
        n = write(si->client_sock[cli_no], buf, strlen(buf));
        free(buf);
    } else {
        n = write(si->client_sock[cli_no], buffer, strlen(buffer));
    }
    if (n <= 0)
        return (-1);
    return (0);
}

void close_connection(struct server_information *si)
{
    close(si->server_sock);
    free(si->arg);
    free(si);
}

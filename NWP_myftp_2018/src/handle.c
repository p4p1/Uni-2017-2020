/*
** EPITECH PROJECT, 2018
** handle.c
** File description:
** <..>
*/

#include "myftp.h"

static char *get_input(struct server_information *si, struct user *us,
        int cli_no)
{
    char    *buf = NULL;
    const char    *tab[15] = { "USER", "PASS", "CWD", "CDUP", "QUIT", "DELE",
        "PWD", "PASV", "PORT", "HELP", "NOOP", "RETR", "STOR", "LIST", NULL };
    int (*ftab[15])(char *, struct server_information *, struct user *, int ) =
        {&cnt_user, &set_pass, &cmd_cwd, &cdup_cmd, &quit_cmd, NULL, &cmd_pwd,
            NULL, NULL, &send_help, &noop, NULL, NULL, &cmd_list, NULL};
    int         i = 0;

    if (si->client_sock[cli_no] < 0)
        return (NULL);
    if ((buf = read_buffer(si, cli_no)) == NULL)
        return (NULL);
    for (i = 0; i < 14; i++) {
        if (strstr(buf, tab[i]) != NULL)
            break;
    }
    if (tab[i] && ftab[i])
        ftab[i](buf, si, us, cli_no);
    else
        send_buffer(si, "500 Unknown command.\n", cli_no);
    return (buf);
}

static unsigned int set_max_fd(struct server_information *si, int i,
        unsigned int max_fd, fd_set *fd)
{
    if (si->client_sock[i] > 0)
        FD_SET(si->client_sock[i], fd);
    if (max_fd < (unsigned int)si->client_sock[i])
        max_fd = (unsigned int)si->client_sock[i];
    if ((unsigned int)si->server_sock > max_fd) {
        FD_SET(si->server_sock, fd);
        max_fd = si->server_sock;
    }
    return (max_fd);
}

static void loop_input_output(struct server_information *si,
        struct user *us, int i, fd_set *fd)
{
    char            *buf = NULL;

    if (FD_ISSET(si->client_sock[i], fd)) {
        buf = get_input(si, us, i);
        if (buf) {
            free(buf);
        } else {
            close (si->client_sock[i]);
            si->client_sock[i] = 0;
            si->logged_in[i] = NOT_LOGGED_IN;
            si->creds[i] = NULL;
        }
    }
}

int handle_client(struct server_information *si, struct user *us)
{
    int             val = 0;
    unsigned int    max_fd = si->server_sock;
    fd_set          fd;

    FD_ZERO(&fd);
    FD_SET(si->server_sock, &fd);
    while (1) {
        max_fd = si->server_sock;
        for (int i = 0; i < CLIENT_NUM; i++)
            max_fd = set_max_fd(si, i, max_fd, &fd);
        if ((val = select(max_fd + 1, &fd, NULL, NULL, NULL)) < 0)
            return (-1);
        if (FD_ISSET(si->server_sock, &fd)) {
            wait_client(si);
        }
        for (int i = 0; i < CLIENT_NUM; i++) {
            loop_input_output(si, us, i, &fd);
        }
    }
    return (0);
}

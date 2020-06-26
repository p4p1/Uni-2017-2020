/*
** EPITECH PROJECT, 2018
** cmd.c
** File description:
** <..>
*/

#include "myftp.h"

int cnt_user(char *buffer, struct server_information *si, struct user *us,
        int cli_no)
{
    struct user *uname = us;

    if (si->logged_in[cli_no] == DONE) {
        send_buffer(si, "232 Already logged in!\n", cli_no);
        return (-1);
    }
    while (uname) {
        if (uname->name && strncmp(uname->name, buffer + 5,
                    strlen(uname->name)) == 0)
            break;
        uname = uname->next;
    }
    if (uname) {
        si->creds[cli_no] = uname;
        send_buffer(si, "331 User name okay, need password.\n", cli_no);
        si->logged_in[cli_no] = NEED_PASS;
    } else {
        send_buffer(si, "331 Unknown user!\n", cli_no);
        return (-1);
    }
    return (0);
}

int set_pass(char *buf, struct server_information *si, struct user *us,
        int cli_no)
{
    struct user *uname = si->creds[cli_no];

    (void) us;
    if (si->logged_in[cli_no] == DONE) {
        send_buffer(si, "232 Already logged in!\n", cli_no);
        return (-1);
    }
    if (si->logged_in[cli_no] == NOT_LOGGED_IN) {
        send_buffer(si, "233 Not logged in!\n", cli_no);
        return (-1);
    }
    if (uname->passwd && strncmp(uname->passwd, buf + 5,
                strlen(uname->passwd)) == 0) {
        si->logged_in[cli_no] = DONE;
        send_buffer(si, "230 User logged in, proceed.\n", cli_no);
    } else {
        send_buffer(si, "234 Incorrect password!\n", cli_no);
        return (-1);
    }
    return (0);
}

int send_help(char *buf, struct server_information *si, struct user *us,
        int cli_no)
{
    (void) buf;
    (void) us;
    if (si->logged_in[cli_no] != DONE) {
        send_buffer(si, "530 Please login with USER and PASS.\n", cli_no);
        return (0);
    }
    send_buffer(si, "214-The following commands are recognized.\n"
    " ABOR ACCT ALLO APPE CDUP CWD  DELE EPRT EPSV FEAT HELP LIST MDTM MKD\n"
    " MODE NLST NOOP OPTS PASS PASV PORT PWD  QUIT REIN REST RETR RMD  RNFR\n"
    " RNTO SITE SIZE SMNT STAT STOR STOU STRU SYST TYPE USER XCUP XCWD XMKD\n"
    " XPWD XRMD\n214 Help OK.\n", cli_no);
    return (0);
}

int noop(char *buf, struct server_information *si, struct user *us,
        int cli_no)
{
    (void) buf;
    (void) us;
    if (si->logged_in[cli_no] != DONE) {
        send_buffer(si, "530 Please login with USER and PASS.\n", cli_no);
    } else {
        send_buffer(si, "200 NOOP ok.\n", cli_no);
    }
    return (0);
}

int quit_cmd(char *buf, struct server_information *si, struct user *us,
        int cli_no)
{
    (void) us;
    (void) buf;
    send_buffer(si, "221 Good bye\n", cli_no);
    close(si->client_sock[cli_no]);
    si->client_sock[cli_no] = 0;
    si->logged_in[cli_no] = NOT_LOGGED_IN;
    si->creds[cli_no] = NULL;
    return (0);
}

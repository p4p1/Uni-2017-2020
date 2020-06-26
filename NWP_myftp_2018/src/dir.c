/*
** EPITECH PROJECT, 2018
** dir.c
** File description:
** <..>
*/

#include "myftp.h"

int cmd_cwd(char *buffer, struct server_information *si, struct user *us,
        int cli_no)
{
    (void) us;
    if (si->logged_in[cli_no] == DONE) {
        chdir(buffer + 4);
        send_buffer(si, "250 Requested file action okay, completed.\n", cli_no);
    } else {
        send_buffer(si, "530 Please login with USER and PASS.\n", cli_no);
    }
    return (0);
}

int cdup_cmd(char *buffer, struct server_information *si, struct user *us,
        int cli_no)
{
    (void) us;
    (void) buffer;
    if (si->logged_in[cli_no] == DONE) {
        if (chdir("..") == -1)
            send_buffer(si, "550 Failed to change directory.\n", cli_no);
        else
            send_buffer(si, "250 Requested file action okay, "
                    "completed.\n", cli_no);
    } else {
        send_buffer(si, "530 Please login with USER and PASS.\n", cli_no);
    }
    return (0);
}

int cmd_pwd(char *buffer, struct server_information *si, struct user *us,
        int cli_no)
{
    (void) us;
    (void) buffer;
    char    *buf;

    if (si->logged_in[cli_no] == DONE) {
        buf = getcwd(NULL, 0);
        send_buffer(si, "257 ", cli_no);
        send_buffer(si, buf, cli_no);
        send_buffer(si, "\n", cli_no);
        free(buf);
    } else {
        send_buffer(si, "530 Please login with USER and PASS.\n", cli_no);
    }
    return (0);
}

int cmd_list(char *buffer, struct server_information *si, struct user *us,
        int cli_no)
{
    DIR *dir;
    struct dirent   *ent;

    (void) us;
    if (si->logged_in[cli_no] != DONE) {
        send_buffer(si, "530 Please login with USER and PASS.\n", cli_no);
        return (0);
    }
    if ((dir = opendir((strlen(buffer + 5) == 0) ?  "." : buffer + 5))
            != NULL) {
        send_buffer(si, "150 File status okay; about to open data"
                "connection.\n", cli_no);
        while ((ent = readdir(dir)) != NULL) {
            send_buffer(si, (ent->d_name[0] == '.') ? "" : ent->d_name, cli_no);
            send_buffer(si, (ent->d_name[0] == '.') ? "" : "\n", cli_no);
        }
        send_buffer(si, "226 Closing data connection.\n", cli_no);
    } else {
        send_buffer(si, "xx No rights for this folder!\n", cli_no);
    }
    return (0);
}

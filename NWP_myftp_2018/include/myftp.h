/*
** EPITECH PROJECT, 2017
** myftp.h
** File description:
** <..>
*/

#ifndef MYFTP_H_
#define MYFTP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <netdb.h>
#include <dirent.h>
#include <netinet/in.h>

#define CLIENT_NUM 10

enum log {
    NOT_LOGGED_IN = 0,
    NEED_PASS = 1,
    DONE = 2
};

struct user {
    char    *name;
    char    *passwd;
    struct user *next;
};

struct argument {
    int     port;
    char    *path;
};

struct server_information {
    int server_sock;
    int client_sock[CLIENT_NUM];
    int logged_in[CLIENT_NUM];
    struct user *creds[CLIENT_NUM];
    struct sockaddr_in  server;
    struct sockaddr_in  client[CLIENT_NUM];
    struct argument     *arg;
};

int wait_client(struct server_information *si);
void close_connection(struct server_information *si);
struct user *get_users(char *file);
char *read_buffer(struct server_information *si, int cli_no);
int send_buffer(struct server_information *si, char *buffer, int cli_no);
int handle_client(struct server_information *si, struct user *us);
int cnt_user(char *buffer, struct server_information *si, struct user *us,
        int cli_no);
int set_pass(char *buf, struct server_information *si, struct user *us,
        int cli_no);
int send_help(char *buf, struct server_information *si, struct user *us,
        int cli_no);
int noop(char *buf, struct server_information *si, struct user *us,
        int cli_no);
int quit_cmd(char *buf, struct server_information *si, struct user *us,
        int cli_no);
int cmd_cwd(char *buffer, struct server_information *si, struct user *us,
        int cli_no);
int cdup_cmd(char *buffer, struct server_information *si, struct user *us,
        int cli_no);
int cmd_pwd(char *buffer, struct server_information *si, struct user *us,
        int cli_no);
int cmd_list(char *buffer, struct server_information *si, struct user *us,
        int cli_no);

#endif

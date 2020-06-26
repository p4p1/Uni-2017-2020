/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** <..>
*/

#include "myftp.h"

static void usage(char *name)
{
    printf("USAGE: %s port path\n"
            "\tport is the port number on wich the server socket listens\n"
            "\tpath is the path to the home directory for the Anonymous user\n"
            , name);
}

static void *destroy(struct server_information *si, char *msg)
{
    fprintf(stderr, "%s\n", msg);
    free(si->arg);
    free(si);
    return (NULL);
}

static struct server_information *create_server(struct argument *arg)
{
    struct server_information *si = malloc(sizeof(struct server_information));

    if (si == NULL || arg == NULL)
        return (NULL);
    si->arg = arg;
    si->server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (si->server_sock == -1)
        return (destroy(si, "could not create socket"));
    for (int i = 0 ; i < CLIENT_NUM; i++) {
        si->client_sock[i] = 0;
        si->logged_in[i] = NOT_LOGGED_IN;
        si->creds[i] = NULL;
    }
    si->server.sin_family = AF_INET;
    si->server.sin_addr.s_addr = INADDR_ANY;
    si->server.sin_port = htons(arg->port);
    if (bind(si->server_sock, (struct sockaddr *)&si->server,
                sizeof(si->server)) > 0)
        return (destroy(si, "could not bind"));
    listen(si->server_sock, 3);
    return (si);
}

static struct argument *arg_set(int ac, char **av)
{
    struct argument *arg = malloc(sizeof(struct argument));

    if (arg == NULL)
        return (NULL);
    if (ac == 2 && !strcmp(av[1], "-help")) {
        usage(av[0]);
        free(arg);
        exit(0);
    } else {
        if (ac == 3) {
            arg->port = atoi(av[1]);
            arg->path = av[2];
            return (arg);
        } else {
            usage(av[0]);
            free(arg);
        }
    }
    return (NULL);
}

int main(int ac, char **av)
{
    struct server_information *si = NULL;
    struct argument *arg = arg_set(ac, av);
    struct user     *root = get_users("./res/passwd.txt");

    (void) root;
    if ((si = create_server(arg)) == NULL)
        return (84);
    if (handle_client(si, root) != 0) {
        close_connection(si);
        return (84);
    }
    close_connection(si);
    return (0);
}

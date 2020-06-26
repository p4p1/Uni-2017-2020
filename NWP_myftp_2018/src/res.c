/*
** EPITECH PROJECT, 2018
** res.c
** File description:
** <..>
*/

#include "myftp.h"

static int to_next(char *line)
{
    int i = 0;

    while (line[i] && line[i] != ' ' && line[i] != '\n')
        i++;
    return (i);
}

static char *get_tkn(char *line, int *l)
{
    int stop = to_next(line + *l);
    int i = 0;
    char    *name = malloc(sizeof(char) * (stop + 1));

    if (name == NULL)
        return (NULL);
    for (i = 0; i < stop; i++)
        name[i] = line[i + *l];
    name[i] = '\0';
    *l = *l + i;
    if (line[*l] == ' ')
        *l = *l + 1;
    return (name);
}

static struct user *create_node(struct user *tmp, char *str, int *j)
{
    tmp->name = get_tkn(str, j);
    tmp->passwd = get_tkn(str, j);
    tmp->next = malloc(sizeof(struct user));
    if (tmp->next == NULL)
        return (NULL);
    memset(tmp->next, 0, sizeof(struct user));
    return (tmp);
}

struct user *get_users(char *file)
{
    struct user *root = malloc(sizeof(struct user));
    struct user *tmp = root;
    char    *str = NULL;
    int     j = 0;
    FILE *fd = fopen(file, "r");

    if (root == NULL)
        return (NULL);
    while (getline(&str, (size_t *)&j,fd) > 0) {
        j = 0;
        if ((tmp = create_node(tmp, str, &j)) == NULL)
            return (NULL);
        tmp = tmp->next;
        free(str);
        j = 0;
        str = NULL;
    }
    free(str);
    return (root);
}

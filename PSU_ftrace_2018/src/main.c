/*
** EPITECH PROJECT, 2019
** ftrace
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include "tools.h"

static int usage(int ret)
{
    fprintf(ret == 0 ? stdout : stderr, "USAGE: ftrace <command>\n");
    return ret;
}

int main(int ac, char **av)
{
    data_t data;

    if (ac < 2)
        return usage(84);
    if (strcmp(av[1], "--help") == 0)
        return usage(0);
    if (getData(&data, av + 1) || check_elf_format(&data))
        return 84;
    start_ftrace(&data);
    return 0;
}

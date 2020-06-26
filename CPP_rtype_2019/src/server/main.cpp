#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "server.hpp"

static void usage(char *name)
{
    printf("%s [OPTION]\n"
            "\t-p\t--port=\t\tSet the port of the server\n", name);
}

static int arguments(char ch, char *name)
{
    if (ch == 'h')
        usage(name);
    else if (ch == '?')
        return (-1);
    return (0);
}

int main(int ac, char *av[])
{
    char    ch = 0;

    while ((ch = getopt(ac, av, "h")) != -1)
        if (arguments(ch, av[0]) < 0)
            return (84);
    try {
        server s;
        s.execute();
    } catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}

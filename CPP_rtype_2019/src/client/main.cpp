/*
** EPITECH PROJECT, 2019
** screen
** File description:
** test
*/

#include "Menu.hpp"
#include "Client.hpp"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>

#include "SFML.hpp"

int usage(char *name)
{
    printf("%s [HOST]\n", name);
    return (84);
}

int main(int ac, char *av[])
{
    SFML    *oui = new SFML(av[1]);

    if (ac != 2)
        return (usage(av[0]));
    oui->draw();
}
/*int main(int ac, char *av[])
{
    Client *c = nullptr;
    protocol::createProtocol    *pro = nullptr;
    struct protocol::proto      *point = nullptr;
    sf::RenderWindow window(sf::VideoMode(640, 480, 32), "SFML Demo");

    if (ac != 2)
        return (usage(av[0]));
    c = new Client(av[1], 1234);
    pro = new protocol::createProtocol();
    usleep(1000000);
    point = pro->askIdentifier();
    pro->displayMessage(point);
    c->send(point);
    c->recvmsg();
    while (1)
    {
        //:pro->displayMessage(c->getProto());

        //pro->displayMessage(point);
        c->recvmsg();
    }
}*/

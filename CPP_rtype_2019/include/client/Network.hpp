/*
** EPITECH PROJECT, 2017
** Network.hpp
** File description:
** <..>
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include "Client.hpp"
class Client;

class Network {
    public:
        Network(Client *_c, protocol::createProtocol *_pro);
        ~Network();
        void shoot(struct protocol::proto *point);
        void move_up(struct protocol::proto *point);
        void move_down(struct protocol::proto *point);
        void move_left(struct protocol::proto *point);
        void move_right(struct protocol::proto *point);
        struct protocol::proto *receive(struct protocol::proto *point);
    private:
        Client *c;
        protocol::createProtocol *pro;
};

#endif

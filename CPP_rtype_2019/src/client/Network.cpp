/*
** EPITECH PROJECT, 2018
** Network.cpp
** File description:
** <..>
*/

#include "Network.hpp"

Network::Network(Client *_c, protocol::createProtocol *_pro)
    : c(_c), pro(_pro)
{}

Network::~Network()
{}

void Network::shoot(struct protocol::proto *point)
{
    point = pro->shoot(point);
    c->send(point);
}
void Network::move_up(struct protocol::proto *point)
{
    point = pro->updatePosition(point, protocol::UP, protocol::PLAYER);
    c->send(point);
}
void Network::move_down(struct protocol::proto *point)
{
    point = pro->updatePosition(point, protocol::DOWN, protocol::PLAYER);
    c->send(point);
}
void Network::move_left(struct protocol::proto *point)
{
    point = pro->updatePosition(point, protocol::LEFT, protocol::PLAYER);
    c->send(point);
}
void Network::move_right(struct protocol::proto *point)
{
    point = pro->updatePosition(point, protocol::RIGHT, protocol::PLAYER);
    c->send(point);
}

struct protocol::proto *Network::receive(struct protocol::proto *point)
{
    c->recvmsg();
    return (c->getProto());
}

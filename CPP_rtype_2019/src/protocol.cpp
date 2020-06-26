/*
** EPITECH PROJECT, 2018
** protocol.cpp
** File description:
** <..>
*/

#include <stdio.h>
#include <string.h>

#include "protocol.hpp"

using namespace protocol;

createProtocol::createProtocol()
    : start_identifier(0)
{}

createProtocol::~createProtocol()
{}

struct proto *createProtocol::shoot(struct proto *tmp)
{
    tmp->type = ATTACK;
    tmp->total_identifier = start_identifier;
    return (tmp);
}

struct proto *createProtocol::hit(struct proto *tmp)
{
    if (tmp != nullptr) {
        tmp->type = UPDATE;
        tmp->mov = DEAD;
        tmp->total_identifier = start_identifier;
    }
    return (tmp);
}

struct proto *createProtocol::updatePosition(struct proto *tmp,
        enum movement mov, enum objType type)
{
    tmp->type = MOVEMENT;
    tmp->object = type;
    tmp->total_identifier = start_identifier;
    tmp->mov = mov;
    return (tmp);
}

struct proto *createProtocol::updateInformation(struct proto *tmp)
{
    tmp->type = UPDATE;
    tmp->mov = NOTHING;
    tmp->total_identifier = start_identifier;
    return (tmp);
}

struct proto *createProtocol::setError(struct proto *tmp)
{
    tmp->type = ERROR;
    tmp->object = PLAYER;
    tmp->total_identifier = start_identifier;
    tmp->mov = NOTHING;
    return (tmp);
}

struct proto *createProtocol::createIdentifier()
{
    struct proto    *tmp = new struct proto;

    tmp->type = CONNECTION;
    tmp->object = PLAYER;
    tmp->mov = NOTHING;
    tmp->identifier = ++start_identifier;
    tmp->total_identifier = start_identifier;
    tmp->x = 100;
    tmp->y = 100;
    return (tmp);
}

struct proto *createProtocol::createBullet(struct proto *shooter)
{
    struct proto    *tmp = new struct proto;

    tmp->type = MOVEMENT;
    tmp->object = BULLET;
    tmp->mov = shooter->mov;
    tmp->identifier = ++start_identifier;
    tmp->total_identifier = start_identifier;
    tmp->x = shooter->x + 100;
    tmp->y = shooter->y + 100;
    return (tmp);
}

struct proto *createProtocol::askIdentifier()
{
    struct proto    *tmp = new struct proto;

    tmp->type = CONNECTION;
    tmp->object = PLAYER;
    tmp->mov = NOTHING;
    tmp->identifier = 0;
    tmp->total_identifier = 0;
    return (tmp);
}

bool createProtocol::compare(struct proto *p1, struct proto *p2)
{
    if (p1->type == p2->type && p1->object == p2->object && p1->mov == p2->mov)
        return (true);
    return (false);
}

void createProtocol::displayMessage(struct proto *msg) const
{
    char    type[6][11] = { "CONNECTION", "MOVEMENT", "ATTACK", "UPDATE", "ERROR",
        nullptr };
    char    obj_type[3][7] = { "PLAYER", "BULLET", nullptr };
    char    mov_type[7][8] = { "NOTHING", "DEAD", "UP", "DOWN", "LEFT", "RIGHT",
        nullptr };

    if (msg != nullptr && msg->type < 6 && msg->type >= 0 && msg->object < 3 && msg->object >= 0 && msg->mov < 7 && msg->mov >= 0) {
        printf("--------------------\n"
                "enum messageType\tstruct->type = %s\n"
                "enum objType\t\tstruct->object = %s\n"
                "enum objType\t\tstruct->mov = %s\n", type[msg->type],
                obj_type[msg->object], mov_type[msg->mov]);
        printf("unsigned int\t\tstruct->identifier = %d\n", msg->identifier);
        printf("unsigned int\t\tstruct->total_identifier = %d\n",
                msg->total_identifier);
    } else {
        printf("Pointer to message is null\n");
    }
}

/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Room.cpp
*/

#include "Room.hpp"

Room::Room(int port)
{
    _port = std::to_string(port);
}

Room::~Room()
{    
}

string Room::getPort()
{
    return (_port);
}

bool Room::ifUserExist(string user)
{
    return (_id_ip.find(user) == _id_ip.end());
}

bool Room::addUser(string user, string ip)
{
    try {
        _id_ip[user] = ip;
        return (true);
    }
    catch (exception &e) {
        return (false);
    }
}

bool Room::deleteUser(string user)
{
    try {
        _id_ip.erase(user);
        return (true);
    }
    catch (exception &e) {
        return (false);
    }
}

map<string, string> Room::getUserMap()
{
    return (_id_ip);
}
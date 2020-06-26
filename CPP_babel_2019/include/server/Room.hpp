/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Room.hpp
*/

#include <vector>
#include <map>

using namespace std;

class Room
{
public:
    Room(int port);
    ~Room();
    string getPort();
    bool ifUserExist(string user);
    bool addUser(string user, string ip);
    bool deleteUser(string user);
    map<string, string> getUserMap(void);
protected:
    string _port;
    map<string, string> _id_ip;
};
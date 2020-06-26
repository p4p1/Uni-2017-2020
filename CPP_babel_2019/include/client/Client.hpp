#pragma once

#include "sockettest.hpp"

class Client
{
public:
    Client(std::string id, std::string host, int port);
    ~Client();
    void Connect();
}
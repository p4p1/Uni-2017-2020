#include "Client.hpp"

Client::Client(std::string id, std::string host, int port)
{
    SocketTest api;
    api.Connect(id, host, port);
}
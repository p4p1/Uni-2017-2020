#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdexcept>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <vector>
#include <arpa/inet.h>
#include <deque>
#include <string.h>
#include "protocol.hpp"
#include "Exception.hpp"

class Client
{

public:
    Client(const std::string& addr, int srcport);
    ~Client();

    int                 get_socket() const;
    int                 get_port() const;
    std::string         get_addr() const;
    int                 recvmsg(void);
    struct protocol::proto *getProto() const;
    int                 send(protocol::proto *msg);

private:
    int                             socketFd;
    struct sockaddr_in              servaddr;
    struct sockaddr_in              clientaddr;
    std::vector<protocol::proto *>  players;
    protocol::proto                 *p;
    void                            managePacket(void);
};

#endif

#include "Client.hpp"
Client::Client(const std::string &addr, int scrport) : p(new protocol::proto)
{
    if ((socketFd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {

        throw Exception("Something went wrong 1");
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(addr.c_str());
    servaddr.sin_port = htons(protocol::port);
    memset(&clientaddr, 0, sizeof(clientaddr));
    clientaddr.sin_family = AF_INET;
    clientaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    do {
        clientaddr.sin_port = htons(scrport++);
    } while (bind(socketFd, (const struct sockaddr *)&clientaddr,
             sizeof(clientaddr)) < 0);
    send(p);
}

Client::~Client()
{
    close(socketFd);
}

int Client::get_socket() const
{
    return socketFd;
}

int Client::send(protocol::proto *msg)
{
    protocol::createProtocol    *pro = new protocol::createProtocol;
    printf("SEND\n");
    pro->displayMessage(msg);
    return sendto(socketFd,(char *)msg, sizeof(protocol::proto), 0, (const struct sockaddr *)&servaddr, sizeof(struct sockaddr));
}

int Client::recvmsg(void)
{
    printf("RECEVING\n");
    memset(p, 0, sizeof(protocol::proto));
    socklen_t len = sizeof(struct sockaddr);
    return recvfrom(socketFd, (void *)p, sizeof(protocol::proto),
                    MSG_DONTWAIT, (struct sockaddr *)&servaddr,
                    &len);
}

struct protocol::proto *Client::getProto() const
{
    return (p);
}

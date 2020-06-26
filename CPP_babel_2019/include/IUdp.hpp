#pragma once

#include <QUdpSocket>

class IUdp
{
public:
    virtual ~IUdp() {};
    virtual bool setting(int port, std::string read_host, std::string write_host) = 0;
    virtual int send(unsigned char *) = 0;
    virtual int read() = 0;
};
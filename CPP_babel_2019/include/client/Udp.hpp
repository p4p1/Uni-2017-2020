#pragma once

#include <QObject>
#include <QUdpSocket>
#include "IUdp.hpp"
#include "Play.hpp"

typedef struct udpProtocol_s
{
    char *id;
    char *msg;
} udpProtocol_t;

class Udp : public IUdp
{
public:
    Udp(Play *);
    bool setting(int port, std::string read_host, std::string write_host);
    int send(unsigned char *);
    int send(std::string);
    int send(sound_protocol_t);
    int read();
    unsigned char *getData();
private:
    QHostAddress _sender;
    quint16 _senderPort;
    QUdpSocket _socket;
    QHostAddress _addr;
    QByteArray _datagram;
    int _port;
    QString _host;
    Play *_play;
};
#include "Udp.hpp"
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <sstream>
#include <iostream>

Udp::Udp(Play *play) : _play(play)
{
}

bool Udp::setting(int port, std::string read_host, std::string write_host)
{
    _port = port;
    _host = QString(write_host.c_str()); //write
    _addr = QHostAddress(read_host.c_str()); //read
    _socket.bind(_addr, _port, QUdpSocket::ShareAddress);
    _play->start();
    return (true);
}

int Udp::send(unsigned char *msg)
{
    QByteArray datagram;

    datagram.append(reinterpret_cast<char *>(msg));
    return _socket.writeDatagram(datagram, QHostAddress(_host), _port);
}

int Udp::send(std::string msg)
{
    QByteArray datagram;

    datagram.append(msg.c_str());
    return _socket.writeDatagram(datagram, QHostAddress(_host), _port);
}

int Udp::send(sound_protocol_t msg)
{
    QByteArray datagram;
    QDataStream s(&datagram, QIODevice::WriteOnly);
    QVector<float> tmp = QVector<float>::fromStdVector(msg.buffer);

    //datagram.append(msg.c_str());
    s << tmp << (qint32)msg.size;
    return _socket.writeDatagram(datagram, QHostAddress(_host), _port);
}

int Udp::read()
{
    QByteArray datagram;
    QVector<float> tmp;
    sound_protocol_t sound;

    datagram.resize(SAMPLE_RATE * 1000);
    _socket.readDatagram(datagram.data(), datagram.size(), &_sender, &_senderPort);
    QDataStream s(datagram);
    s >> tmp;
    if (tmp.size() == 0)
        return (0);
    sound.buffer = std::vector<float>(tmp.toStdVector());
    sound.size = (int)sound.buffer.size();
    if (sound.size == 0)
        return (0);
    //for (auto it = sound.buffer.begin(); it != sound.buffer.end(); it++)
    //    std::cout << *it << std::endl;
    _play->setSound(sound);
    _datagram = datagram;
    return (sound.size);
}

unsigned char *Udp::getData()
{
    return (reinterpret_cast<unsigned char *>(_datagram.data()));
}
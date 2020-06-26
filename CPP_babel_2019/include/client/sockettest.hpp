#ifndef SOCKETTEST_H
#define SOCKETTEST_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QCoreApplication>
#include <map>
#include <functional>
#include <set>
#include "Udp.hpp"

class SocketTest : public QObject
{
    Q_OBJECT
public:
    explicit SocketTest(QObject *parent = 0, Udp *udp = nullptr, char *host = "localhost");

    void Connect(std::string host, int port);

signals:

public slots:
    void connected();
    void disconnected();
    void bytesWritten (qint64 bytes);
    void readyRead();

private:
    QTcpSocket *socket;
    Udp *udp;
    std::map<std::string, std::function<void(void )>> _cmd;
    std::set<std::string> command_list;
    std::string _id;
    std::string _my_port;
    std::string _host;
    void getId();
    void getPwd();
    void getCreateRoom();
    void getJoinRoom();
    void getExit();
    void getRequest();
    void startCall(std::string);
};

#endif // SOCKETTEST_H

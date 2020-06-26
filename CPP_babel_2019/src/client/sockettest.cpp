#include "sockettest.hpp"
#include <iostream>
#include "audio.hpp"
#include "Opus.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Record.hpp"

std::vector<std::string> parseString(std::string target, char delim)
{
    std::vector<std::string> ret;
    std::stringstream ss(target);
    std::string tmp;

    while (getline(ss, tmp, delim)) {
        ret.push_back(tmp);
    }
    return (ret);
}

SocketTest::SocketTest(QObject *parent, Udp *udp, char *host) :
    QObject(parent), udp(udp), _host(host)
{
    _cmd["id"] = std::bind(&SocketTest::getId, this);
    _cmd["pwd"] = std::bind(&SocketTest::getPwd, this);
    _cmd["createroom"] = std::bind(&SocketTest::getCreateRoom, this);
    _cmd["joinroom"] = std::bind(&SocketTest::getJoinRoom, this);
    _cmd["exit"] = std::bind(&SocketTest::getExit, this);
    _cmd["request"] = std::bind(&SocketTest::getRequest, this);
    command_list = {"id", "pwd", "createroom", "joinroom", "exit", "request"};
}

void SocketTest::Connect(std::string hostname, int port)
{
    socket = new QTcpSocket(this);
    socket->connectToHost(hostname.c_str(), port);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void SocketTest::connected()
{
    qDebug() << "Connection";
    std::string id;

    std::cout << "port:" << std::endl;
    std::cin >> id;
    _my_port = id;
    std::cout << "id:";
    std::cin >> id;
    _id = id;
    socket->write("id:");
    socket->write(id.c_str());
    socket->waitForBytesWritten(3000);
}

void SocketTest::disconnected()
{
    qDebug() << "Disconnection";
}

void SocketTest::bytesWritten (qint64 bytes)
{
    qDebug() << "wrote" << bytes;
}

void SocketTest::startCall(std::string message)
{
    std::cout << "Got " << message << " as server msg" << std::endl;
    std::vector<std::string> args = parseString(message, ':');
    int room_port = stoi(args.front());

    if (args.size() > 1) {
        udp->setting(room_port, _host, args.back());
        std::cout << "Read host:" << _host << std::endl;
        std::cout << "Write host:" << args.back() << std::endl;
        sound_protocol_t msg;
        Record rec(udp);
        if (rec.start())
            std::cout << "Start\n";
        while (true)
            udp->read();
            //    std::cout << "Read something!" << std::endl;
    }
    socket->write("request");
    socket->waitForBytesWritten(3000);
}

void SocketTest::readyRead()
{
    socket->waitForReadyRead(3000);
    std::string msg = socket->readAll().data();
    std::string type = msg.substr(0, msg.find(":"));
    std::string content = msg.substr(msg.find(":") + 1, msg.length() - 1);
    if (command_list.find(type) != command_list.end())
        _cmd[type]();
    else {
        //Udp udp;
        //udp.call(msg); // launch calls from all the ip
        startCall(msg);
        //udp->call(msg);
        //startCall(msg);
    }
}

void SocketTest::getId()
{
    std::string password;
    socket->waitForBytesWritten(3000);
    std::cout << "Password:";
    std::cin >> password;
    socket->write("pwd:");
    socket->write(password.c_str());
}

void SocketTest::getPwd()
{
    int choice;
    socket->waitForBytesWritten(3000);
    std::cout << "1 to create room\n2 to join a room:" << std::endl;
    std::cin >> choice;
    if (choice == 1) {
        std::string room_name;
        int room_port;
        std::cout << "Room name:";
        std::cin >> room_name;
        std::cout << "Room port:";
        std::cin >> room_port;
        socket->write("createroom:");
        socket->write(room_name.c_str());
        socket->write(":");
        socket->write(std::to_string(room_port).c_str());
        //_host = HOST_CREATE;
    }
    else {
        std::string room_name;
        std::cout << "Room name:";
        std::cin >> room_name;
        socket->write("joinroom:");
        socket->write(room_name.c_str());
        //_host = HOST_JOIN;
    }
}

void SocketTest::getCreateRoom()
{
    socket->waitForBytesWritten(3000);
    std::cout << "Create Room is valid and sending request\n";
    socket->write("request");
}

void SocketTest::getJoinRoom()
{
    socket->waitForBytesWritten(3000);
    std::cout << "Join Room is done and sending request\n";
    socket->write("request");
}

void SocketTest::getExit()
{
    socket->waitForBytesWritten(3000);
    socket->close();
}

void SocketTest::getRequest()
{
    socket->waitForBytesWritten(3000);
}
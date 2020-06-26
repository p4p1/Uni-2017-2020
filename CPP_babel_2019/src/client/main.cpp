#include <QCoreApplication>
#include "sockettest.hpp"
#include <iostream>
#include "Udp.hpp"
#include "Play.hpp"

int main(int argc, char *argv[])
{
    if (argc == 3) {
        QCoreApplication a(argc, argv);

        Play *play = new(Play);
        Udp *udp = new Udp(play);
        SocketTest cTest(0, udp, argv[1]);
        cTest.Connect(argv[1], atoi(argv[2]));
        a.exec();
        return 0;
    }
    else {
        std::cout << "Error: Requires hostname and port number of the running server" << std::endl;
        return (84);
    }
}
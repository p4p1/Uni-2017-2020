#ifndef UDPSERVER_HPP_
#define UDPSERVER_HPP_

#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <thread>

class UdpServer
{
public:
    UdpServer(boost::asio::io_service &io_service);

private:
    void startReceive(void);

    void handleReceive(const boost::system::error_code &error,
                       std::size_t bytes_transferred);

    void handleSend(std::shared_ptr<std::string> message,
                    const boost::system::error_code &ec,
                    std::size_t bytes_transferred);
    void checkIn(void);
    void checkOut(void);
 /*   void test(void){
        std::lock_guard<std::mutex> guard(m);
        static int i = 0;
        i++;
        std::cout << i << "\n";
    }*/
    boost::asio::ip::udp::socket _socket;
    boost::asio::ip::udp::endpoint _remoteEndpoint;
    std::array<char, 1024> _recvBuffer;
    std::mutex  m;
    static unsigned int nbSession;
};

#endif

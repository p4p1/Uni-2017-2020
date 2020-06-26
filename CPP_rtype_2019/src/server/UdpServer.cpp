#include "UdpServer.hpp"

UdpServer::UdpServer(boost::asio::io_service &io_service)
    : _socket(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 1111))
{
    startReceive();
}

void UdpServer::startReceive(void)
{
    _recvBuffer.fill(0);
    _socket.async_receive_from(
        boost::asio::buffer(_recvBuffer), _remoteEndpoint,
        boost::bind(&UdpServer::handleReceive, this,
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::bytes_transferred));
}

void UdpServer::handleReceive(const boost::system::error_code &error,
                              std::size_t bytes_transferred)
{
    if (!error || error == boost::asio::error::message_size)
    {

        auto message = std::make_shared<std::string>(_recvBuffer.data());

        _socket.async_send_to(boost::asio::buffer(*message), _remoteEndpoint,
                              boost::bind(&UdpServer::handleSend, this, message,
                                          boost::asio::placeholders::error,
                                          boost::asio::placeholders::bytes_transferred));
    }
    else{
        checkOut();
        _socket.close();
    }
}

void UdpServer::checkIn(void)
{
    std::lock_guard<std::mutex> guard(m);
}

void UdpServer::checkOut(void)
{
    std::lock_guard<std::mutex> guard(m);
}

void UdpServer::handleSend(std::shared_ptr<std::string> message,
                           const boost::system::error_code &ec,
                           std::size_t bytes_transferred)
{
    startReceive();
}

/*
** EPITECH PROJECT, 2018
** server.cpp
** File description:
** <..>
*/

#include "server.hpp"

server::server()
    : io_service_(), socket_(io_service_, udp::endpoint(udp::v4(), protocol::port))
{
    pro = new createProtocol;
    gameEn = new Engine;
    socket_.async_receive_from(
        boost::asio::buffer(data_, MAX_LENGTH), sender_endpoint_,
        boost::bind(&server::handle_receive_from, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

server::~server()
{
    delete pro;
}

void server::execute()
{
    io_service_.run();
}

void server::run_command()
{
    if (data_->type == CONNECTION) {
        data_ = pro->createIdentifier();
        gameEn->addElement(data_);
    } else if (data_->type == MOVEMENT) {
        gameEn->updateMovement(data_);
        data_ = pro->updateInformation(data_);
    } else if (data_->type == ATTACK) {
        gameEn->addElement(pro->createBullet(data_));
    } else if (data_->type == UPDATE) {
        data_ = gameEn->getElement(data_->identifier);
    } else {
        data_ = pro->setError(data_);
    }
}

void server::handle_receive_from(const boost::system::error_code& error,
    size_t bytes_recvd)
{
    struct proto *tmp = nullptr;

    gameEn->updateBullet();
    run_command();
    printf("RECEIVE %p\n", data_);
    pro->displayMessage(data_);
    if (!error && bytes_recvd > 0) {
        if ((tmp = gameEn->isDead()) != nullptr)
            data_ = pro->hit(tmp);
        socket_.async_send_to(
            boost::asio::buffer(data_, bytes_recvd), sender_endpoint_,
            boost::bind(&server::handle_send_to, this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
    } else {
        socket_.async_receive_from(
            boost::asio::buffer(data_, MAX_LENGTH), sender_endpoint_,
            boost::bind(&server::handle_receive_from, this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
    }
}

void server::handle_send_to(const boost::system::error_code& error,
        size_t bytes_sent)
{
    printf("SEND %p\n", data_);
    pro->displayMessage(data_);
    socket_.async_receive_from(
        boost::asio::buffer(data_, MAX_LENGTH), sender_endpoint_,
        boost::bind(&server::handle_receive_from, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

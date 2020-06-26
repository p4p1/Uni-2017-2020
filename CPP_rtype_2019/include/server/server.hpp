/*
** EPITECH PROJECT, 2017
** current-file-name
** File description:
** <..>
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

#include "Engine.hpp"

#define MAX_LENGTH protocol::buffer_size

using boost::asio::ip::udp;

class server {
    public:
        server();
        ~server();
        void execute();
        void run_command();
        void handle_receive_from(const boost::system::error_code& error,
                      size_t bytes_recvd);
        void handle_send_to(const boost::system::error_code& error,
                      size_t bytes_sent);
    private:
        boost::asio::io_service io_service_;
        udp::socket             socket_;
        udp::endpoint           sender_endpoint_;
        struct proto            *data_;
        createProtocol          *pro;
        Engine                  *gameEn;
};

#endif

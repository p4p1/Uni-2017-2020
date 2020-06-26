#pragma once

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <vector>
#include <map>
#include <functional>
#include "Room.hpp"
#include "ISession.hpp"

using namespace std;
using boost::asio::ip::tcp;

class Server;

class Session : public ISession
{
private:
  map<string, function<void(string)>> _commands;
  void handle_read(const boost::system::error_code& error, size_t bytes_transferred);
  void treat_message();
  void handle_write(const boost::system::error_code& e);
  void write_some(const string &message, const string &flag="");
  void read_some();
  void command_id(string content);
  void command_pwd(string content);
  void command_createroom(string content);
  void command_joinroom(string content);
  void command_request(string content);
  void command_exit(string content);
    tcp::socket socket_;
    enum {
          max_length = 1024
          };  
  char data_[max_length];
  string _id;
  string _password;
  Server *_target_server;
  string _roomname;
  string _ip;

public:
  Session(boost::asio::io_service& io_service, Server *target_server);
  ~Session();
  tcp::socket& socket();
  void start();
};

class Server
{
private:
  void start_accept();
  void handle_accept(Session *new_session, const boost::system::error_code& error);
  boost::asio::io_service& io_service_;
  tcp::acceptor acceptor_;
public:
  map<string, Room *> _room_clients; // roomname : Class Room
  map<string, string> id_pwd; // contains the id as key and a pwd as a value
  Server(boost::asio::io_service& io_service, short port);
  ~Server();
};
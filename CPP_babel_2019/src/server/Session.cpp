/*
** EPITECH PROJECT, 2019
** include
** File description:
** Session.cpp
*/

#include "Server.hpp"
#include <iostream>
#include <QObject>
#include <QMutex>
#include <QDebug>

Session::Session(boost::asio::io_service& io_service, Server *target_server) : socket_(io_service), _target_server(target_server)
{
    _id = "";
    _password = "";
    _commands["id"] = bind(&Session::command_id, this, placeholders::_1);
    _commands["pwd"] = bind(&Session::command_pwd, this, placeholders::_1);
    _commands["createroom"] = bind(&Session::command_createroom, this, placeholders::_1);
    _commands["joinroom"] = bind(&Session::command_joinroom, this, placeholders::_1);
    _commands["request"] = bind(&Session::command_request, this, placeholders::_1);
    _commands["exit"] = bind(&Session::command_exit, this, placeholders::_1);
}

Session::~Session()
{}

void Session::command_exit(string content)
{
    cout << "here" << endl;
    try {
        if (_target_server->_room_clients[content])
            _target_server->_room_clients[content]->deleteUser(_id);
        write_some("exit", ":OK");
        cout << "EXIT good\n";
        socket_.close();
    }
    catch (exception &e) {
        write_some("exit", ":KO");
        cout << "Error on exit\n ";
    }
}

void Session::command_id(string content)
{
    // check if there is an id in the database
    _id = content;
    cout << "id is now set to " << content << endl;
    write_some("id", ":OK");
}

void Session::command_pwd(string content)
{
    if (_id == "") {
        write_some("pwd", ":KO");
        return;
    }
    _password = content;
    cout << "password is " << content << endl;
    write_some("pwd", ":OK");
}

void Session::command_createroom(string content)
{
    try
    {
        string name = content.substr(0, content.find(":"));
        string port = content.substr(content.find(":") + 1, content.length() - 1);
        cout << name << ":" << port << endl;
        Room *instence_room = new Room(stoi(port));

        _target_server->_room_clients.insert(make_pair(name, instence_room));
        _target_server->_room_clients[name]->addUser(_id, _ip);
        _roomname = name;
        write_some("createroom", ":OK");
    }
    catch (exception &e)
    {
        write_some("createroom", ":KO");
        return;
    }
}

void Session::command_joinroom(string content)
{
    if (_target_server->_room_clients[content] != NULL)
            _target_server->_room_clients[content]->addUser(_id, _ip);
    else {
        _target_server->_room_clients.erase(content);
        write_some("joinroom", ":KO");
        return;
    }
    _roomname = content;
    write_some("joinroom", ":OK");
}

void Session::command_request(string content)
{
    std::string final_message;
    for (auto it = _target_server->_room_clients.begin(); it != _target_server->_room_clients.end(); it++) {
        std::cout << it->first << std::endl;
        if (it->first == _roomname) {
            final_message = it->second->getPort();
            map<string, string> dic = it->second->getUserMap();
            for (auto host = dic.begin(); host != dic.end(); host++) {
                std::cout << "compare : " << _id << " : " << host->first << " who contains " << host->second << std::endl;
                if (host->first != _id) {
                    std::cout <<  "ID differs and put " << host->second << " in the message\n";
                    final_message += ":" + host->second;
                }
            }
        }
        else
            std::cout << it->first << " is not in the " << _roomname << std::endl;
    }
    std::cout << "final_message is:" << final_message << std::endl;
    write_some(final_message.c_str());
    std::cout << "request:OK" << std::endl;
}

tcp::socket& Session::socket()
{
    return socket_;
}

void Session::write_some(const string &message, const string &flag)
{
    int len_flag = 0;
    if (flag != "")
        len_flag = 1;
    boost::asio::async_write(socket_, boost::asio::buffer(message + flag, message.length() + flag.length() + len_flag),
				     boost::bind(&Session::handle_write, this, boost::asio::placeholders::error));
}

void Session::read_some()
{
  socket_.async_read_some(boost::asio::buffer(data_, max_length),
			  boost::bind(&Session::handle_read,
				      this,
				      boost::asio::placeholders::error,
				      boost::asio::placeholders::bytes_transferred));
  cout << "Test" << endl;
}

void Session::start()
{
    cout << "connected" << endl;
    cout << socket_.remote_endpoint().address().to_string() << endl;
    _ip = socket_.remote_endpoint().address().to_string();
    read_some();
}

void Session::treat_message()
{
    try {
        string message = data_;
        message.erase(remove(message.begin(), message.end(), '\n'), message.end());
        string command = message.substr(0, message.find(":"));
        string content = message.substr(message.find(":") + 1, message.length() - 1);
        cout << "Got " << command << " : " << content << endl;
        _commands[command](content);
    }
    catch (exception &e) {
        cout << e.what() << endl;
    }
}

void Session::handle_read(const boost::system::error_code& error, size_t bytes_transferred)
{
    treat_message();
    read_some();
    for (int i = 0; i != max_length; i++)
        data_[i] = 0;
}

void Session::handle_write(const boost::system::error_code& e)
{
}
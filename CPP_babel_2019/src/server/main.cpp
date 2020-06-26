/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** main.cpp
*/

#include "Server.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    try
    {
      if (argc != 2)
	        return (84);
        boost::asio::io_service io_service;
        Server s(io_service, atoi(argv[1]));
        io_service.run();
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
        return (2);
    }
    return 0;
}

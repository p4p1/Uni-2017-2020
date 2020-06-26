/*
** EPITECH PROJECT, 2018
** Buzz.cpp
** File description:
** <..>
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string name, std::string fname)
	: Toy(Toy::BUZZ, name, fname)
{}

Buzz::~Buzz()
{}

void Buzz::speak(const std::string str)
{
	std::cout << "BUZZ: " << _name << " \"" << str << "\"" << std::endl;
}

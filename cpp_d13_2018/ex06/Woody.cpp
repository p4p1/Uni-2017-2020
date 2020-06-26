/*
** EPITECH PROJECT, 2018
** Woody.cpp
** File description:
** <..>
*/

#include "Woody.hpp"

Woody::Woody(std::string name, std::string fname)
	: Toy(Toy::WOODY, name, fname)
{}

Woody::~Woody()
{}

void Woody::speak(const std::string str)
{
	std::cout << "WODDY: " << _name << " \"" << str << "\"" << std::endl;
}

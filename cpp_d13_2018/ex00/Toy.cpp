/*
** EPITECH PROJECT, 2018
** Toy.cpp
** File description:
** <..>
*/

#include "Toy.hpp"

Toy::Toy(enum ToyType type, std::string name, std::string fname)
	: _type(type), _name(name), _pic(fname)
{}

Toy::~Toy()
{}

enum Toy::ToyType Toy::getType() const
{
	return _type;
}

std::string Toy::getName() const
{
	return _name;
}

void Toy::setName(std::string name)
{
	_name = name;
}

bool Toy::setAscii(std::string file_name)
{
	return _pic.getPictureFromFile(file_name);
}

std::string Toy::getAscii() const
{
	return _pic.data;
}

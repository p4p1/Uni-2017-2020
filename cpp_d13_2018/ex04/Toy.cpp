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

void Toy::setAxii(std::string str)
{
	_pic.data = str;
}

std::string Toy::getAscii() const
{
	return _pic.data;
}

void Toy::speak(const std::string str)
{
	if (_type == Toy::BUZZ)
		std::cout << "BUZZ: " << _name << " \"" << str << "\"" << std::endl;
	else if (_type == Toy::WOODY)
		std::cout << "WOODY: " << _name << " \"" << str << "\"" << std::endl;
	else
		std::cout << _name << " \"" << str << "\"" << std::endl;
}

Toy& operator+=(Toy& lhs, const Toy& rhs)
{
	lhs.setAxii(lhs.getAscii() + rhs.getAscii());
	lhs.setName(lhs.getName() + rhs.getName());
	return lhs;
}

std::ostream& operator<<(std::ostream &os, Toy &rhs)
{
	os << rhs.getName() << std::endl << rhs.getAscii() << std::endl;
	return os;
}

Toy& Toy::operator<<(const std::string &str)
{
	setAxii(str);
	return *this;
}

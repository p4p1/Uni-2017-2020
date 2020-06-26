/*
** EPITECH PROJECT, 2018
** Toy.cpp
** File description:
** <..>
*/

#include "Toy.hpp"

Toy::Toy(enum ToyType type, std::string name, std::string fname)
	: _type(type), _name(name), _pic(fname)
{
	if (type == BUZZ)
		_span = true;
	else
		_span = false;
}

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
	bool	b = _pic.getPictureFromFile(file_name);

	if (b == false) {
		err.type = Error::PICTURE;
		err._what = "bad new illustration";
		err._where = "setAscii";
	}
	return b;
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
		std::cout << "WODDY: " << _name << " \"" << str << "\"" << std::endl;
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

bool Toy::speak_es(const std::string str)
{
	if (_span) {
		std::cout << "BUZZ: " << _name << " senorita \"" << str
			<< "\" senorita" << std::endl;
	} else {
		err.type = Error::SPEAK;
		err._what = "wrong mode";
		err._where = "speak_es";
		return false;
	}
	return true;
}
Toy::Error Toy::getLastError()
{
	return err;
}

std::string Toy::Error::what()
{
	return _what;
}
std::string Toy::Error::where()
{
	return _where;
}

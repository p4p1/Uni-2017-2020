/*
** EPITECH PROJECT, 2018
** Sorcerer.cpp
** File description:
** <..>
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title)
	: _name(name), _title(title)
{
	std::cout << name << ", " << title << "is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << _name << ", " << _title << " is dead. Consequences will never be the same!"
		<< std::endl;
}

std::string Sorcerer::getName() const
{
	return _name;
}

std::string Sorcerer::getTitle() const
{
	return _title;
}

void Sorcerer::polymorph(const Victim &victim)
{
	victim.getPolymorphed();
}

void Sorcerer::polymorph(const Peon &victim)
{
	victim.getPolymorphed();
}

std::ostream& operator<<(std::ostream &os, const Sorcerer &sor)
{
	os << "I am " << sor.getName() << ", " << sor.getTitle()
		<< ", and I like ponies!" << std::endl;
	return os;
}

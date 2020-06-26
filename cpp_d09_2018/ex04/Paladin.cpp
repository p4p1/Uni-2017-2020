/*
** EPITECH PROJECT, 2018
** Paladin.cpp
** File description:
** <..>
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int level, std::string weapon)
	: Character(name, level), Mage(name, level), Warrior(name, level, weapon), Priest(name, level)
{
	std::cout << "the light falls on " << name << std::endl;
}

Paladin::~Paladin()
{}

void Paladin::RestorePower()
{
	_power = 100;
	std::cout << _name << " eats" << std::endl;
}

int Paladin::Intercept()
{
	if (_power < 10) {
		std::cout << _name << " out of power" << std::endl;
		return 0;
	}
	std::cout << _name <<" intercepts" << std::endl;
	_power -= 10;
	Range = CLOSE;
	return 0;
}

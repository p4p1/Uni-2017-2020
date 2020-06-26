/*
** EPITECH PROJECT, 2018
** Priest.cpp
** File description:
** <..>
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int level)
	: Character(name, level), Mage(name, level)
{
	std::cout << name << " enters in the order" << std::endl;
}

Priest::~Priest()
{}

int Priest::CloseAttack()
{
	if (_power < 10) {
		std::cout << _name << " out of power" << std::endl;
		return 0;
	}
	std::cout << _name << " uses a spirit explosion" << std::endl;
	_power -= 10;
	Range = RANGE;
	return 10 + Spirit;
}

void Priest::Heal()
{
	if (_power < 10) {
		std::cout << _name << " out of power" << std::endl;
		return;
	}
	std::cout << _name << " casts a little heal pspell" << std::endl;
	_pv += 70;
}

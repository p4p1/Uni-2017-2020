/*
** EPITECH PROJECT, 2018
** Mage.cpp
** File description:
** <..>
*/

#include "Mage.hpp"

Mage::Mage(const std::string &name, int level)
	:Character(name, level)
{
	_pv = 100;
	_power = 100;
	Stamina = 6;
	Spirit = 11;
	Agility = 7;
	Intelligence = 12;
	Strength = 6;
	std::cout << name << " teleported" << std::endl;
}

Mage::~Mage()
{}

int Mage::CloseAttack()
{
	if (_power < 10) {
		std::cout << _name << " out of power" << std::endl;
		return 0;
	}
	std::cout << _name << " blinks" << std::endl;
	_power -= 10;
	Range = RANGE;
	return 0;
}

int Mage::RangeAttack()
{
	if (_power < 25) {
		std::cout << _name << " out of power" << std::endl;
		return 0;
	}
	std::cout << _name << " launches a fire ball" << std::endl;
	_power -= 25;
	return 20 + Spirit;
}

void Mage::RestorePower()
{
	_power += 50 + Intelligence;
	std::cout << _name << " takes a mana potion" << std::endl;
}

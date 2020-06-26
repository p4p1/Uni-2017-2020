/*
** EPITECH PROJECT, 2018
** Warrior.cpp
** File description:
** <..>
*/

#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level, std::string weaponName)
	: Character(name, level), _weaponName(weaponName)
{
	_pv = 100;
	_power = 100;
	Stamina = 12;
	Spirit = 5;
	Agility = 7;
	Intelligence = 6;
	Strength = 12;
	std::cout << "I'm " << _name << "  KKKKKKKKKKRRRRRRRRRRRRRREEEE"
		"EEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior()
{}

int Warrior::CloseAttack()
{
	if (_power < 30) {
		std::cout << _name << " out of power" << std::endl;
		return 0;
	}
	if (_weaponName.compare("Hammer") == 0) {
		std::cout << _name << " strikes with his " << _weaponName  << std::endl;
		_power -= 10;
		return 20 + Strength;
	}
	return 0;
}

int Warrior::RangeAttack()
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

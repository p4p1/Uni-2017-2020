/*
** EPITECH PROJECT, 2018
** Character.cpp
** File description:
** <..>
*/

#include "Character.hpp"

Character::Character(const std::string &name, int level)
	:_name(name), _level(level), _pv(100), _power(100), Stamina(5),
	Spirit(5), Agility(5), Intelligence(5), Strength(5)
{}

Character::~Character()
{}

const std::string &Character::getName() const
{
	return _name;
}

int Character::getLvl() const
{
	return _level;
}

int Character::getPv() const
{
	return _pv;
}

int Character::getPower() const
{
	return _power;
}

int Character::CloseAttack()
{
	if (_power < 10) {
		std::cout << _name << " out of power" << std::endl;
		return 0;
	}
	std::cout << _name << " strikes with a wooden stick" << std::endl;
	_power -= 10;
	return 10 + Strength;
}

int Character::RangeAttack()
{
	if (_power < 10) {
		std::cout << _name << " out of power" << std::endl;
		return 0;
	}
	std::cout << _name <<" tosses a stone" << std::endl;
	_power -= 10;
	return 5 + Strength;
}

void Character::Heal()
{
	_pv += 50;
	std::cout << _name << " takes a potion" << std::endl;
}

void Character::RestorePower()
{
	_power = 100;
	std::cout << _name << " eats" << std::endl;
}

void Character::TakeDamage(int damage)
{
	_pv -= damage;
	if (_pv > 0) {
		std::cout << _name << " takes " << damage << " damage" << std::endl;
	} else {
		std::cout << _name << " out of combat" << std::endl;
	}
}

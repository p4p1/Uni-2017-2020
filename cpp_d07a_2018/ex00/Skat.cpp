/*
** EPITECH PROJECT, 2018
** Skat.cpp
** File description:
** <..>
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name="bob", int stimPaks=15)
	: _stimPaks(stimPaks),
	_name(name)
{}
Skat::~Skat()
{}

int Skat::stimPaks()
{
	return _stimPaks;
}

const std::string &Skat::name()
{
	return _name;
}

void Skat::shareStimPaks(int number, int &stock)
{
	if (stock > number) {
		std::cout << "Don't be greedy" << std::endl;
	} else {
		stock += number;
		_stimPaks -= number;
		std::cout << "Keep the change." << std::endl;
	}
}

void Skat::addStimPaks(unsigned int number)
{
	if (number == 0) {
		std::cout << "Hey boya, did you forget something?" << std::endl;
	} else {
		_stimPaks += number;
	}
}

void Skat::useStimPaks()
{
	if (_stimPaks) {
		_stimPaks--;
		std::cout << "Time to kick some ass and chew"
			"bubble gum." << std::endl;
	} else {
		std::cout << "Mediiiiiic" << std::endl;
	}
}

void Skat::status()
{
	std::cout << "Soldier " << _name << " reporting ";
	std::cout << _stimPaks << " stimpaks remaining sir!" << std::endl;
}

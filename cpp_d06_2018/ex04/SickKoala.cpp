/*
** EPITECH PROJECT, 2018
** SickKoala.cpp
** File description:
** <..>
*/

#include "SickKoala.hpp"

#include <string.h>

SickKoala::SickKoala(std::string name)
	: _name(name)
{}

SickKoala::~SickKoala()
{
	std::cout << "Mr." << _name;
	std::cout << ": Krooogg!! I'm cuuuured !" << std::endl;
}

std::string SickKoala::get_name()
{
	return (_name);
}

void SickKoala::poke()
{
	std::cout << "Mr." << _name;
	std::cout << ": Gooeeeeerrk !!" << std::endl;
}

bool SickKoala::takeDrug(std::string drug)
{
	if (strcasecmp(drug.c_str(), "mars") == 0) {
		std::cout << "Mr." << _name;
		std::cout << ": Mars , and it kreogs !";
		std::cout << std::endl;
		return true;
	}
	if (drug.compare("Buronzand") == 0) {
		std::cout << "Mr." << _name;
		std::cout << ": And you 'll sleep";
		std::cout << "right away !" << std::endl;
		return true;
	}
	std::cout << "Mr." << _name;
	std::cout << ": Goerkreog !" << std::endl;
	return false;
}
void SickKoala::overDrive(std::string str)
{
	size_t	idx = 0;

	while ((idx = str.find("Kreog!")) != std::string::npos)
		str.replace(idx, 6, "1337!");
	std::cout << "Mr." << _name << ": ";
	std::cout << str << std::endl;
}

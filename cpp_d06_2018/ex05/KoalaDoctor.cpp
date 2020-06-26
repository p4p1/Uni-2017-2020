/*
** EPITECH PROJECT, 2018
** KoalaDoctor.cpp
** File description:
** <..>
*/

#include <fstream>
#include <stdlib.h>

#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name)
	: _name(name)
{
	std::cout << "Dr." << name << ": I'm Dr.";
	std::cout << name << "! How do you kreog ?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{}

void KoalaDoctor::diagnose(SickKoala *patient)
{
	char	tab[5][16] = { "mars", "Buronzand", "Viagra", "Extasy",
		"Eucalyptus leaf" };
	int	no = random() % 5;
	std::ofstream	ofs(patient->get_name() + ".report");

	std::cout << "Dr." << _name << ": So what's goerking you Mr.";
	std::cout << patient->get_name() << std::endl;
	patient->poke();
	if (ofs.is_open()) {
		ofs << tab[no];
	}
}

void KoalaDoctor::timeCheck()
{
	static unsigned int	shlag = 0;

	if (shlag == 0) {
		std::cout << "Dr." << _name;
		std::cout << ": Time to get to work !" << std::endl;
		shlag = 1;
	} else {
		std::cout << "Dr." << _name;
		std::cout << ": Time to go home to my eucalyptus forest !";
		std::cout << std::endl;
		shlag = 0;
	}
}

string KoalaDoctor::getName()
{
	return _name;
}

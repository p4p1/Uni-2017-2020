/*
** EPITECH PROJECT, 2018
** KoalaNurse.cpp
** File description:
** <..>
*/

#include <iostream>
#include <fstream>

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int id)
	: _id(id)
{}

KoalaNurse::~KoalaNurse()
{
	std::cout << "Nurse" << _id;
	std::cout << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
	patient->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string file_name)
{
	std::ifstream	ifs(file_name, std::ifstream::in);
	char		c = 0;
	size_t		pos = 0;
	std::string		drug_name = "";
	std::string		patient =
		file_name.substr(0, file_name.find("."));

	if (ifs) {
		c = ifs.get();
		while (ifs.good() ){
			drug_name += c;
			c = ifs.get();
		}
		while ((pos = drug_name.find('\n')) != std::string::npos)
			drug_name.erase(pos);
		ifs.close();
		std::cout << "Nurse" << _id;
		std::cout << ": Kreog! Mr." << patient << " needs a ";
		std::cout << drug_name << "!" << std::endl;
	}
	return drug_name;
}

void KoalaNurse::timeCheck()
{
	static unsigned int	shlag = 0;

	if (shlag == 0) {
		std::cout << "Nurse" << _id;
		std::cout << ": Time to get to work !" << std::endl;
		shlag = 1;
	} else {
		std::cout << "Nurse" << _id;
		std::cout << ": Time to go home to my eucalyptus forest !";
		std::cout << std::endl;
		shlag = 0;
	}
}

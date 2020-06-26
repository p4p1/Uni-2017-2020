/*
** EPITECH PROJECT, 2017
** SickKoala.hpp
** File description:
** <..>
*/

#ifndef SICK_KOALA_HPP_
#define SICK_KOALA_HPP_

#include <iostream>

class SickKoala {
	public:
		SickKoala(std::string name);
		~SickKoala();
		void poke();
		bool takeDrug(std::string drug);
		void overDrive(std::string str);

	private:
		std::string	_name;
};

#endif

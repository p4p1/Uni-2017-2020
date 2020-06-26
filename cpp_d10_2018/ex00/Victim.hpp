/*
** EPITECH PROJECT, 2017
** Victim.hpp
** File description:
** <..>
*/

#ifndef VICTIM_HPP_
#define VICTIM_HPP_

#include <iostream>

class Victim {
	public:
		Victim(std::string name);
		~Victim();
		std::string getName() const;
		void getPolymorphed() const;

	protected:
		std::string _name;
};

std::ostream& operator<<(std::ostream &os, const Victim &vic);

#endif

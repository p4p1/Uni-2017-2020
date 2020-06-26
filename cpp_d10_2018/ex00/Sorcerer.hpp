/*
** EPITECH PROJECT, 2017
** Sorcerer.hpp
** File description:
** <..>
*/

#ifndef SORCERER_HPP_
#define SORCERER_HPP_

#include <iostream>

#include "Victim.hpp"
#include "Peon.hpp"

class Sorcerer {
	public:
		Sorcerer(std::string name, std::string title);
		~Sorcerer();
		std::string getName() const;
		std::string getTitle() const;
		void polymorph(const Victim &victim);
		void polymorph(const Peon &victim);

	private :
		std::string _name;
		std::string _title;
};

std::ostream& operator<<(std::ostream &os, const Sorcerer &sor);

#endif

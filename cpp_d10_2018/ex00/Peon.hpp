/*
** EPITECH PROJECT, 2017
** Peon.hpp
** File description:
** <..>
*/

#ifndef PEON_HPP_
#define PEON_HPP_

#include "Victim.hpp"

class Peon: public Victim {
	public:
		Peon(std::string name);
		~Peon();
		void getPolymorphed() const;
};

#endif

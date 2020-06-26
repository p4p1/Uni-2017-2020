/*
** EPITECH PROJECT, 2017
** Priest.hpp
** File description:
** <..>
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Mage.hpp"

class Priest: public Mage {
	public:
		Priest(const std::string &name, int level);
		~Priest();

		int CloseAttack();
		void Heal();
};

#endif

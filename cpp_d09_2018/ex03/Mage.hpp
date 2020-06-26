/*
** EPITECH PROJECT, 2017
** Mage.hpp
** File description:
** <..>
*/

#ifndef MAGE_HPP_
#define MAGE_HPP_

#include "Character.hpp"

class Mage: public Character {
	public:
		Mage(const std::string &name, int level);
		~Mage();

		int CloseAttack();
		int RangeAttack();

		void RestorePower();
};

#endif

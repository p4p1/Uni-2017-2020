/*
** EPITECH PROJECT, 2017
** Warrior.hpp
** File description:
** <..>
*/

#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_

#include "Character.hpp"

class Warrior: public Character {
	public:
		Warrior(const std::string &name, int level, std::string weaponName);
		~Warrior();

		int CloseAttack();
		int RangeAttack();
	private:
		std::string _weaponName;
};

#endif

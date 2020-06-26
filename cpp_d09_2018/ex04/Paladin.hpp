/*
** EPITECH PROJECT, 2017
** Paladin.hpp
** File description:
** <..>
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Priest.hpp"
#include "Warrior.hpp"

class Paladin: public Warrior, public Priest {
	Paladin(const std::string &name, int level, std::string weapon);
	~Paladin();
	using Priest::Heal;
	using Priest::RangeAttack;
	using Warrior::CloseAttack;
	int Intercept();
	void RestorePower();
};

#endif

/*
** EPITECH PROJECT, 2017
** Character.hpp
** File description:
** <..>
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <iostream>

class Character {
	public:
		enum AttackRange {
			CLOSE, RANGE
		};

		Character(const std::string &name, int level);
		~Character();
		const std::string &getName() const;
		int getLvl() const;
		int getPv() const;
		int getPower() const;

		int CloseAttack();
		int RangeAttack();
		void Heal();
		void RestorePower();
		void TakeDamage(int damage);

		int Range;

	private:
		const std::string	&_name;
		int			_level;
		int			_pv;
		int			_power;

	protected:
		int			Stamina;
		int			Spirit;
		int			Agility;
		int			Intelligence;
		int			Strength;
};

#endif

/*
** EPITECH PROJECT, 2017
** Droid.hpp
** File description:
** <..>
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <iostream>

#include "DroidMemory.hpp"

class Droid {
	public:
		Droid(std::string Id);
		~Droid();
		Droid(const Droid &other);
		Droid &operator=(const Droid &rhs);
		bool operator==(const Droid &rhs) const;
		bool operator!=(const Droid &rhs) const;
		Droid &operator<<(size_t &rhs);
		std::string getId() const;
		void setId(std::string Id);
		std::string getStatus() const;
		void setStatus(std::string *Status);
		size_t getEnergy() const;
		void setEnergy(size_t Energy);
		DroidMemory *getDroidMemory();
		void setDroidMemory(DroidMemory *_BattleData);

	private:
		std::string	_Id;
		std::string	*_Status;
		size_t		_Energy;
		const size_t	_Attack = 25;
		const size_t	_Toughness = 15;
		DroidMemory	*BattleData;
};

std::ostream& operator<<(std::ostream& os, Droid &rhs);

#endif

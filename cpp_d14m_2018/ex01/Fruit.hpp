/*
** EPITECH PROJECT, 2017
** Fruit.hpp
** File description:
** <..>
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <iostream>

class Fruit {
	public:
		Fruit(int vitamins);
		~Fruit();
		int getVitamins();
		std::string getName();
	protected:
		std::string	_name;
		int		_vitamins;
};

#endif

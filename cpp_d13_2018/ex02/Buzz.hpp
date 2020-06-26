/*
** EPITECH PROJECT, 2017
** Buzz.hpp
** File description:
** <..>
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz: public Toy {
	public:
		Buzz(std::string name="", std::string fname="buzz.txt");
		~Buzz();
};

#endif

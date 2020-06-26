/*
** EPITECH PROJECT, 2017
** Woody.hpp
** File description:
** <..>
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody: public Toy {
	public:
		Woody(std::string name="", std::string fname="woody.txt");
		~Woody();
		void speak(const std::string str);
};

#endif

/*
** EPITECH PROJECT, 2017
** ToyStory.hpp
** File description:
** <..>
*/

#ifndef TOYSTORY_HPP_
#define TOYSTORY_HPP_

#include <iostream>
#include <fstream>

#include "Toy.hpp"

class ToyStory {
	public:
		ToyStory();
		~ToyStory();
		class tellMeAStory {
			public:
				tellMeAStory(std::string fname, Toy toy1,
					bool (Toy::*func1)(std::string str), Toy toy2,
					bool (Toy::*func2)(std::string str));
				~tellMeAStory();
		};
};

#endif

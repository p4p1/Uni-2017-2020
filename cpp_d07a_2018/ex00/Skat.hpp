/*
** EPITECH PROJECT, 2017
** Skat.hpp
** File description:
** <..>
*/

#ifndef SKAT_HPP_
#define SKAT_HPP_

#include <iostream>

class Skat {
	public:
		Skat(const std::string &name="bob", int stimPaks=15);
		~Skat();

		int stimPaks();
		const std::string &name();

		void shareStimPaks(int number, int& stock);
		void addStimPaks(unsigned int number);
		void useStimPaks();
		void status();
	private:
		int _stimPaks;
		const std::string &_name;
};

#endif

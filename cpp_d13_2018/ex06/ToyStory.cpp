/*
** EPITECH PROJECT, 2018
** ToyStory.cpp
** File description:
** <..>
*/

#include "ToyStory.hpp"

ToyStory::ToyStory()
{}

ToyStory::~ToyStory()
{}

static void process_line_t1(Toy toy1, std::string line,
		bool (Toy::*func1)(std::string str))
{
	if (line.find("picture:") == std::string::npos) {
		toy1->*func1(line);
	}
}

static void process_line_t2(Toy toy1, std::string line,
		bool (Toy::*func1)(std::string str))
{
	if (line.find("picture:") == std::string::npos) {
		toy1->*func1(line);
	}
}

ToyStory::tellMeAStory::tellMeAStory(std::string fname, Toy toy1,
		bool (Toy::*func1)(std::string str), Toy toy2,
		bool (Toy::*func2)(std::string str))
{
	std::ifstream	ifs(fname);
	std::string	line;
	int		i = 0;

	if (ifs.is_open()) {
		std::cout << toy1.getAscii() << std::endl;
		std::cout << toy2.getAscii() << std::endl;
		while (std::getline(ifs, line)) {
			if (i % 2)
				process_line_t1(toy1, line, func1);
			else
				process_line_t2(toy2, line, func2);
			i++;
		}
	} else {
		std::cout << "tellMeAStory: can't open file" << std::endl;
	}
}

ToyStory::tellMeAStory::~tellMeAStory()
{}

/*
** EPITECH PROJECT, 2018
** Picture.cpp
** File description:
** <..>
*/

#include "Picture.hpp"

Picture::Picture(const std::string &file)
{
	std::ifstream	ifs(file, std::ifstream::in);
	char		c = 0;

	if (!file.empty() && !ifs) {
		data = "ERROR";
	} else if (file.empty()) {
		data = "";
	} else {
		data.clear();
		c = ifs.get();
		while (ifs.good()) {
			data += c;
			c = ifs.get();
		}
	}
}

Picture::~Picture()
{}

bool Picture::getPictureFromFile(const std::string &file)
{
	std::ifstream	ifs(file, std::ifstream::in);
	char		c = 0;

	if (!ifs) {
		data = "ERROR";
		return (false);
	} else {
		data.clear();
		c = ifs.get();
		while (ifs.good()) {
			data += c;
			c = ifs.get();
		}
	}
	return (true);
}

Picture& operator+= (Picture& lhs, const Picture &rhs)
{
	lhs.data += rhs.data;
	return lhs;
}

/*
** EPITECH PROJECT, 2017
** Picture.hpp
** File description:
** <..>
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <iostream>
#include <fstream>

class Picture {
	public:
		Picture(const std::string &file="");
		~Picture();
		bool getPictureFromFile(const std::string &file);
		std::string data;
};

#endif

/*
** EPITECH PROJECT, 2017
** Parser.hpp
** File description:
** <..>
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <cstdlib>
#include <ctype.h>
#include <stack>
#include <iostream>

class Parser {
	public:
		Parser();
		~Parser();
		void feed(const std::string &str);
		int result() const;
		void reset();

	private:
		int	res;
		std::stack<int>	num;
		std::stack<char>	op;
};

#endif

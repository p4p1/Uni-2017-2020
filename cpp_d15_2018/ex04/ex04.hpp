/*
** EPITECH PROJECT, 2017
** ex04.hpp
** File description:
** <..>
*/

#ifndef EX04_HPP_
#define EX04_HPP_

template<typename T>
bool equal(const T &a, const T &b);

template<typename T>
class Tester {
	public:
		Tester() = default;
		~Tester() = default;
		bool equal(const T &a, const T &b);
};

#include "ex04.cpp"

#endif

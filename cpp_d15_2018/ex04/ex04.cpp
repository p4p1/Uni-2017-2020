/*
** EPITECH PROJECT, 2018
** ex04.cpp
** File description:
** <..>
*/

#include "ex04.hpp"

#ifndef EX04_CPP_
#define EX04_CPP_

template<typename T>
bool Tester<T>::equal(const T &a, const T &b)
{
	if (a == b)
		return true;
	return false;
}

template<typename T>
bool equal(const T &a, const T &b)
{
	if (a == b)
		return true;
	return false;
}

#endif

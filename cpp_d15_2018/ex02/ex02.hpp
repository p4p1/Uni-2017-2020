/*
** EPITECH PROJECT, 2017
** ex02.hpp
** File description:
** <..>
*/

#ifndef EX02_HPP_
#define EX02_HPP_

#include <iostream>

template<typename T>
T min(T a, T b)
{
	std::cout << "template min" << std::endl;
	if (b < a)
		return b;
	return a;
}

template<typename T>
T templateMin(T *tab, int len)
{
	T	val = tab[0];

	for (int i = 1 ; i < len; i++) {
		val = min(val, tab[i]);
	}
	return val;
}

int min(int a, int b)
{
	std::cout << "non-template min" << std::endl;
	if (b < a)
		return b;
	return a;
}

int nonTemplateMin(int *tab, int len)
{
	int	val = tab[0];

	for (int i = 1 ; i < len; i++) {
		val = min(val, tab[i]);
	}
	return val;
}

#endif

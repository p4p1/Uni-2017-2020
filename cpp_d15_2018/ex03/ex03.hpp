/*
** EPITECH PROJECT, 2017
** ex03.hpp
** File description:
** <..>
*/

#ifndef EX03_HPP_
#define EX03_HPP_

#include <iostream>

template<typename T>
void foreach(T *tab, void (*func)(const T &elem), int siz)
{
	for (int i = 0; i < siz; i++) {
		func(tab[i]);
	}
}

template<typename T>
void print(const T &elem)
{
	std::cout << elem << std::endl;
}

#endif

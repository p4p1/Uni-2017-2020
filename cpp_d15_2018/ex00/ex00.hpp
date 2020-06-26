/*
** EPITECH PROJECT, 2017
** ex00.hpp
** File description:
** <..>
*/

#ifndef EX00_HPP_
#define EX00_HPP_

template<typename T>
void swap(T &a, T &b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T a, T b)
{
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>
T max(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}

template <typename T>
T add(T a, T b)
{
	return a + b;
}

#endif

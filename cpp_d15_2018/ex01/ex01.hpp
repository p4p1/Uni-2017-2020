/*
** EPITECH PROJECT, 2017
** ex01.hpp
** File description:
** <..>
*/

#ifndef EX01_HPP_
#define EX01_HPP_

#include <string.h>

template<typename T>
int compare(const T &a, const T &b)
{
	if (a == b)
		return 0;
	if (a > b)
		return 1;
	return -1;
}

int compare(const char *a, const char *b)
{
	int	no = strcmp(a, b);

	if (no == 0)
		return (0);
	if (no < 0)
		return (-1);
	return (1);
}

#endif

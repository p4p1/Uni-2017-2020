/*
** EPITECH PROJECT, 2018
** main.cpp
** File description:
** <..>
*/

#include "ex05.hpp"

#include <iostream>

int main()
{
	array<int> a(1);
	a[0] = 42;
	const auto b = a;
	std::cout << b[0] << std::endl;
}

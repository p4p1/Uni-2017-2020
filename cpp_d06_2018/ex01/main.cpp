/*
** EPITECH PROJECT, 2018
** main.cpp
** File description:
** <..>
*/

#include <iostream>
#include <iomanip>
#include <math.h>

enum type {
	CELSIUS,
	FARENHEIT
};

static void tmp_conversion(float no, enum type tp)
{
	float	res = 0;

	if (tp == CELSIUS) {
		res =  5.0 / 9.0 * (no - 32);
		std::cout << std::fixed;
		std::cout << std::setw(16);
		std::cout << std::setprecision(3) << res;
		std::cout << std::setw(16);
		std::cout << "Celsius" << std::endl;
	} else if (tp == FARENHEIT) {
		res =  5.0 / 9.0 * (no - 32);
		std::cout << std::fixed;
		std::cout << std::setw(16);
		std::cout << std::setprecision(3) << res;
		std::cout << std::setw(16);
		std::cout << "Fahrenheit" << std::endl;
	}
}

int main()
{
	std::string	line;
	std::string	delim = " ";
	std::string	token;
	float		num;

	std::getline(std::cin, line);
	num = stoi(line);
	while (line.find(delim) != line.npos)
		line.erase (0, line.find(delim) + delim.length());
	token = line.substr(0, line.find(delim));
	if (line.compare("Celsius") == 0)
		tmp_conversion(num, FARENHEIT);
	else if (line.compare("Fahrenheit") == 0)
		tmp_conversion(num, CELSIUS);
	line.erase (0, line.find(delim) + delim.length());
}

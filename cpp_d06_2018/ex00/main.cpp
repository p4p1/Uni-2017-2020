/*
** EPITECH PROJECT, 2018
** main.cpp
** File description:
** <..>
*/

#include <iostream>
#include <fstream>

static void open_file(char *name)
{
	std::ifstream	ifs(name, std::ifstream::in);
	char		c = 0;

	if (!ifs) {
		std::cerr << "my_cat: ";
		std::cerr << name;
		std::cerr << ": No such file or directory" << std::endl;
	} else {
		c = ifs.get();
		while (ifs.good() ){
			std::cout << c;
			c = ifs.get();
		}
		ifs.close();
	}
}

int main(int ac, char **av)
{
	if (ac > 1) {
		for (int i = 1; i < ac; i++) {
			open_file(av[i]);
		}
	} else {
		std::cerr << "my_cat: Usage: " << av[0];
		std::cerr << " file [...]" << std::endl;
	}
	return 0;
}

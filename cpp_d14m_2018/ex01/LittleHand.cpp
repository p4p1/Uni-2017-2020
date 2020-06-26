/*
** EPITECH PROJECT, 2018
** LittleHand.cpp
** File description:
** <..>
*/

#include "LittleHand.hpp"

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons,
				FruitBox &bananas, FruitBox &limes)
{
	Fruit	*froot = nullptr;
	std::string	str;
	bool		val = true;
	FruitBox	bin(unsorted.nbFruits());

	while ((froot = unsorted.pickFruit()) != NULL && val) {
		str = froot->getName();
		if (!str.compare("lemon")) {
			val = lemons.putFruit(froot);
		} else if (!str.compare("banana")) {
			val = bananas.putFruit(froot);
		} else if (!str.compare("lime")) {
			val = limes.putFruit(froot);
		} else {
			val = bin.putFruit(froot);
		}
	}
	while ((froot = bin.pickFruit()) != NULL && val) {
		val = unsorted.putFruit(froot);
	}
}

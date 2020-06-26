/*
** EPITECH PROJECT, 2017
** FruitBox.hpp
** File description:
** <..>
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox {
	public:
		FruitBox(int size);
		~FruitBox();
		int nbFruits();
		bool putFruit(Fruit *f);
		Fruit *pickFruit();
		FruitNode *head();
	private:
		FruitNode	*_element;
		FruitNode	*_head;
		FruitNode	*_tail;
};

#endif

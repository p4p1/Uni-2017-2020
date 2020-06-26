/*
** EPITECH PROJECT, 2018
** FruitBox.cpp
** File description:
** <..>
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size)
{
	_element = new FruitNode;

	_head = _element;
	for (int i = 0; i < size; i++) {
		_element->token = nullptr;
		_element->next = new FruitNode;
		_element = _element->next;
	}
	_element->next = nullptr;
	_tail = _element;
	_element = _head;
}

FruitBox::~FruitBox()
{
	FruitNode	*tmp;

	_element = nullptr;
	_tail = nullptr;
	while (_head->next != nullptr) {
		tmp = _head;
		_head = _head->next;
		free(tmp);
	}
}

int FruitBox::nbFruits()
{
	int	inc = 0;

	_element = _head;
	while (_element && _element != _tail) {
		if (_element->token)
			inc++;
		_element = _element->next;
	}
	return (inc);
}

bool FruitBox::putFruit(Fruit *f)
{
	_element = _head;
	while (_element && _element != _tail) {
		if (_element->token == nullptr) {
			_element->token = f;
			return (true);
		}
		_element = _element->next;
	}
	return (false);
}

Fruit *FruitBox::pickFruit()
{
	Fruit	*tmp;

	_element = _head;
	while (_element && _element != _tail) {
		if (_element->token != nullptr) {
			tmp = _element->token;
			_element->token = nullptr;
			return (tmp);
		}
		_element = _element->next;
	}
	return (nullptr);
}

FruitNode *FruitBox::head()
{
	return _head;
}

void FruitBox::disp()
{
	_element = _head;
	while (_element && _element != _tail) {
		if (_element->token != nullptr) {
			std::cout << _element->token->getName() << std::endl;
		}
		_element = _element->next;
	}
}

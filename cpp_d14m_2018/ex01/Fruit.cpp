/*
** EPITECH PROJECT, 2018
** Fruit.cpp
** File description:
** <..>
*/

#include "Fruit.hpp"

Fruit::Fruit(int vitamins)
	: _vitamins(vitamins)
{}

Fruit::~Fruit()
{}

std::string Fruit::getName()
{
	return _name;
}

int Fruit::getVitamins()
{
	return _vitamins;
}

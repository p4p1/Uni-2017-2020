/*
** EPITECH PROJECT, 2019
** screen
** File description:
** test
*/

#ifndef SCREEN_HPP_
#define SCREEN_HPP_

#include <SFML/Graphics.hpp>

class Screen {
	public:
		virtual int Run(sf::RenderWindow &Window) = 0;
};

#endif /* !SCREEN_HPP_ */
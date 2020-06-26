/*
** EPITECH PROJECT, 2019
** menu
** File description:
** test
*/

#include "Menu.hpp"
#include <iostream>

Menu::Menu() {
	max = 3 * 255;
	div = 3;
	play = false;
	run = true;
	i = 0;
	menu = 0;
}

void Menu::SetTexture() {
	_TextMenu.setFont(_Font);
	_TextMenu.setCharacterSize(20);
	_TextMenu.setString("PLAY");
	_TextMenu.setPosition({280.f, 160.f});

	_TextExit.setFont(_Font);
	_TextExit.setCharacterSize(20);
	_TextExit.setString("EXIT");
	_TextExit.setPosition({280.f, 220.f});
}

int Menu::LoadTexture() {
	if (!_Texture.loadFromFile("res/Texture/Menu.jpg")) {
		std::cerr << "Error when try to load Texture from Texture/Menu.png" << std::endl;
		return -1;
	}
	_Sprite.setTexture(_Texture);
	_Sprite.setColor(sf::Color(255, 255, 255, i));
	if (!_Font.loadFromFile("res/Font/verdana.ttf")) {
		std::cerr << "Error when try to load file for font fron FOnt/verdana.ttf" << std::endl;
		return -1;
	}
	return 0;
}

int Menu::CheckEvent(sf::RenderWindow &Window) {
	while (Window.pollEvent(_Event)) {
		if (_Event.type == sf::Event::Closed)
			return -1;
		if (_Event.type == sf::Event::KeyPressed) {
			switch (_Event.key.code) {
			case sf::Keyboard::Up:
				menu = 0;
				break;
			case sf::Keyboard::Down:
				menu = 1;
				break;
			case sf::Keyboard::Return:
				if (menu == 0) {
					play = true;
					return 1;
				} else
					return -1;
				break;
			default:
				break;
			}
		}
	}
	return 0;
}

int Menu::Run(sf::RenderWindow &Window) {
	LoadTexture();
	SetTexture();
	if (play)
		i = max;
	while (run) {
		CheckEvent(Window);
		if (i < max)
			i++;
		_Sprite.setColor(sf::Color(255, 255, 255, i / div));
		if (menu == 0) {
			_TextMenu.setFillColor(sf::Color(255, 0, 0, 255));
			_TextExit.setFillColor(sf::Color(255, 255, 255, 255));
		}
		Window.clear();
		Window.draw(_Sprite);
		if (i == max) {
			if (!play)
				Window.draw(_TextMenu);
			Window.draw(_TextExit);
		}
		Window.display();
	}
	return -1;
}

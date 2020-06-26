/*
** EPITECH PROJECT, 2019
** menu
** File description:
** rtype
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "Screen.hpp"

class Menu : public Screen {
	public:
		Menu();
		~Menu() {}
		void SetTexture();
		int LoadTexture();
		int CheckEvent(sf::RenderWindow &Window);
		virtual int Run(sf::RenderWindow &Window);
	private:
		int max;
		int div;
		int play;
		sf::Event _Event;
		bool run;
		sf::Texture _Texture;
		sf::Sprite _Sprite;
		int i;
		sf::Font _Font;
		sf::Text _TextMenu;
		sf::Text _TextExit;
		int menu;
};

#endif /* !MENU_HPP_ */

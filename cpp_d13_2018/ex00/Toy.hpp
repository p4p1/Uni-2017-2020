/*
** EPITECH PROJECT, 2017
** Toy.hpp
** File description:
** <..>
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Picture.hpp"

class Toy {
	public:
		enum ToyType {
			BASIC_TOY,
			ALIEN
		};
		Toy(enum ToyType type=BASIC_TOY, std::string name="toy", std::string fname="");
		~Toy();
		enum ToyType getType() const;
		std::string getName() const;
		void setName(std::string name);
		bool setAscii(std::string file_name);
		std::string getAscii() const;

	private:
		ToyType	_type;
		std::string	_name;
		Picture		_pic;
};

#endif

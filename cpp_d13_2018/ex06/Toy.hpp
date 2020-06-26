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
		class  Error {
			public:
				enum ErrorType {
					UNKNOWN,
					PICTURE,
					SPEAK
				};
				std::string what();
				std::string where();
				std::string	_what;
				std::string	_where;
				enum ErrorType	type;
		};
		enum ToyType {
			BASIC_TOY,
			ALIEN,
			BUZZ,
			WOODY
		};
		Toy(enum ToyType type=BASIC_TOY, std::string name="toy", std::string fname="");
		~Toy();

		enum ToyType getType() const;
		std::string getName() const;
		void setName(std::string name);
		bool setAscii(std::string file_name);
		std::string getAscii() const;
		void setAxii(std::string str);
		void speak(const std::string str);
		Toy& operator<<(const std::string &str);
		bool speak_es(const std::string str);
		Error getLastError();

	protected:
		ToyType		_type;
		std::string	_name;
		Picture		_pic;
		bool		_span;
		Error		err;
};

Toy& operator+=(Toy& lhs, const Toy& rhs);
std::ostream& operator<<(std::ostream &os, Toy &rhs);

#endif

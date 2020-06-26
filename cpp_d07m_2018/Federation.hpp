/*
** EPITECH PROJECT, 2017
** Federation.hpp
** File description:
** <..>
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <iostream>

#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Federation {
	namespace Starfleet {
		class Captain {
			public:
				Captain(std::string name);
				~Captain();
				std::string getName();
				int getAge();
				void setAge(int age);
			private:
				std::string	_name;
				int		_age;
		};
		class Ship {
			public:
				Ship(int length, int width, std::string name,
						short maxWarp);
				~Ship();
				void setupCore(WarpSystem::Core *core);
				void checkCore();
				void promote(Federation::Starfleet::Captain *captain);
				bool move(int warp, Destination d);
				bool move(int warp);
				bool move(Destination d);
			private:
				int			_length;
				int			_width;
				std::string		_name;
				short			_maxWarp;
				WarpSystem::Core	*_core;
				Captain			*_captain;
				Destination		_location;
				Destination		_home;
		};
		class Ensign {
			public:
				Ensign(std::string name);
				~Ensign();
			private:
				std::string _name;
		};
	}
	class Ship {
		public:
			Ship(int length, int width, std::string name);
			~Ship();
			void setupCore(WarpSystem::Core *core);
			void checkCore();
			bool move(int warp, Destination d);
			bool move(int warp);
			bool move(Destination d);
		private:
			int			_length;
			int			_width;
			std::string		_name;
			short			_maxWarp;
			WarpSystem::Core	*_core;
			Destination		_location;
			Destination		_home;
	};
}

#endif

/*
** EPITECH PROJECT, 2017
** Borg.hpp
** File description:
** <..>
*/

#ifndef BORG_HPP_
#define BORG_HPP_

#include "Federation.hpp"
#include "WarpSystem.hpp"

namespace Borg {
	class Ship {
		public:
			Ship();
			~Ship();
			void setupCore(WarpSystem::Core *core);
			void checkCore();
			bool move(int warp, Destination d);
			bool move(int warp);
			bool move(Destination d);
		private:
			int			_side;
			short			_maxWarp;
			WarpSystem::Core	*_core;
			Destination		_location;
			Destination		_home;
	};
}

#endif

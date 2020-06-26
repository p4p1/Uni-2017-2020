/*
** EPITECH PROJECT, 2017
** WarpSystem.hpp
** File description:
** <..>
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

namespace WarpSystem {
	class QuantumReactor {
		public:
			QuantumReactor();
			~QuantumReactor();
			bool isStable();
			void setStability(bool stability);
		private:
			bool _stability;
	};
	class Core {
		public:
			Core(QuantumReactor *);
			~Core();
			QuantumReactor *checkReactor();
		private:
			QuantumReactor	*_coreReactor;
	};
}

#endif

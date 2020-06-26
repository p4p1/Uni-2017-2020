/*
** EPITECH PROJECT, 2017
** DoidMemory.hpp
** File description:
** <..>
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <iostream>

class DroidMemory {
	public:
		DroidMemory();
		~DroidMemory();
		void setFingerPrint(size_t _FingerPrint);
		size_t getFingerPrint() const;
		void setExp(size_t _Exp);
		size_t getExp() const;
		DroidMemory &operator<<(DroidMemory &rhs);
		DroidMemory &operator>>(DroidMemory &rhs);
		DroidMemory &operator+=(DroidMemory &rhs);
		DroidMemory &operator+=(size_t no);
		DroidMemory operator+(const DroidMemory &droidMem) const;

	private:
		size_t	FingerPrint;
		size_t	Exp;
};

std::ostream& operator<<(std::ostream& os, DroidMemory &rhs);

#endif

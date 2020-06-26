/*
** EPITECH PROJECT, 2018
** DoidMemory.cpp
** File description:
** <..>
*/

#include <stdlib.h>

#include "DroidMemory.hpp"

DroidMemory::DroidMemory()
	: FingerPrint(random()), Exp(0)
{}

DroidMemory::~DroidMemory()
{}

void DroidMemory::setFingerPrint(size_t _FingerPrint)
{
	FingerPrint = _FingerPrint;
}

size_t DroidMemory::getFingerPrint() const
{
	return FingerPrint;
}

void DroidMemory::setExp(size_t _Exp)
{
	Exp = _Exp;
}

size_t DroidMemory::getExp() const
{
	return Exp;
}

DroidMemory &DroidMemory::operator<<(DroidMemory &rhs)
{
	this->setExp(this->getExp() + rhs.getExp());
	this->setFingerPrint(this->getFingerPrint() ^ rhs.getExp());
	return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &rhs)
{
	rhs.setExp(rhs.getExp() + this->getExp());
	rhs.setFingerPrint(rhs.getFingerPrint() ^ this->getExp());
	return rhs;
}

DroidMemory &DroidMemory::operator+=(DroidMemory &rhs)
{
	this->setExp(this->getExp() + rhs.getExp());
	this->setFingerPrint(this->getFingerPrint() ^ rhs.getExp());
	return *this;
}

DroidMemory &DroidMemory::operator+=(size_t no)
{
	this->setExp(this->getExp() + no);
	this->setFingerPrint(this->getFingerPrint() ^ no);
	return *this;
}

DroidMemory DroidMemory::operator+(const DroidMemory &droidMem) const
{
	DroidMemory newDroidMem;

	newDroidMem.setExp(droidMem.getExp() + this->getExp());
	newDroidMem.setFingerPrint(this->getFingerPrint() ^ droidMem.getExp());
	return newDroidMem;
}

std::ostream& operator<<(std::ostream& os, DroidMemory &rhs)
{
	os << "DroidMemory '" << rhs.getFingerPrint() << "', " << rhs.getExp();
	return os;
}

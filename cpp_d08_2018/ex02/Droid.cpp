/*
** EPITECH PROJECT, 2018
** Droid.cpp
** File description:
** <..>
*/

#include "Droid.hpp"
#include <stdio.h>

Droid::Droid(std::string Id)
	: _Id(Id),
	_Status(new std::string("Standing by")),
	_Energy(50)
{
	std::cout << "Droid '" << _Id << "' Activated" << std::endl;
}

Droid::~Droid()
{
	std::cout << "Droid '" << _Id << "' Destroyed" << std::endl;
	delete _Status;
}

Droid::Droid(const Droid &other)
	:_Id(other.getId()),
	_Status(new std::string(other.getStatus())),
	_Energy(other.getEnergy())
{
	std::cout << "Droid '" << _Id << "' Activated, Memory Dumped" << std::endl;
}

std::string Droid::getId() const
{
	return _Id;
}

void Droid::setId(std::string Id)
{
	_Id = Id;
}

std::string Droid::getStatus() const
{
	return *_Status;
}

void Droid::setStatus(std::string *Status)
{
	_Status = Status;
}

size_t Droid::getEnergy() const
{
	return _Energy;
}

void Droid::setEnergy(size_t Energy)
{
	_Energy = Energy;
}

Droid &Droid::operator=(const Droid &rhs)
{
	std::string	Status = rhs.getStatus();
	_Id = rhs.getId();
	_Energy = rhs.getEnergy();
	_Status = new std::string(Status);
	return *this;
}

bool Droid::operator==(const Droid &rhs) const
{
	if (*_Status == rhs.getStatus())
		return true;
	return false;
}

bool Droid::operator!=(const Droid &rhs) const
{
	if (*_Status != rhs.getStatus())
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, Droid &rhs)
{
	os << "Droid '" << rhs.getId() << "', " << rhs.getStatus() << ", "
		<< rhs.getEnergy();
	return os;
}

Droid &Droid::operator<<(size_t &rhs)
{
	size_t	val = 100 - this->getEnergy();

	if (val && val <= rhs) {
		rhs -= val;
		this->setEnergy(this->getEnergy() + val);
	}
	return *this;
}

void Droid::setDroidMemory(DroidMemory *_BattleData)
{
	BattleData = _BattleData;
}

DroidMemory *Droid::getDroidMemory()
{
	return BattleData;
}

/*
** EPITECH PROJECT, 2018
** Federation.cpp
** File description:
** <..>
*/

#include "Federation.hpp"

Federation::Starfleet::Ensign::Ensign(std::string name)
	:_name(name)
{
	std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{}

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
	: _length(length),
	_width(width),
	_name(name),
	_maxWarp(maxWarp),
	_location(EARTH),
	_home(EARTH)
{
	std::cout << "The ship USS " << name << " has been finished.";
	std::cout  << std::endl << "It is " << length << " m in length and ";
	std::cout << width << " m in width." << std::endl;
	std::cout << "It can go to Warp " << maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
	this->_core = core;
	std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
	WarpSystem::QuantumReactor *iz = _core->checkReactor();

	std::cout << "USS " << _name << ": The core is ";
	if (iz->isStable())
		std::cout << "stable";
	else
		std::cout << "unstable";
	std::cout << " at the time." << std::endl;
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain)
{
	std::cout << captain->getName() << ": I'm glad to be the captain of the USS ";
	std::cout << _name << "." << std::endl;
	_captain = captain;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
	WarpSystem::QuantumReactor *iz = _core->checkReactor();

	if (warp <= _maxWarp && d != _location && iz->isStable()) {
		_location = d;
		return (true);
	}
	return (false);
}

bool Federation::Starfleet::Ship::move(int warp)
{
	WarpSystem::QuantumReactor *iz = _core->checkReactor();

	if (warp <= _maxWarp && _home != _location && iz->isStable()) {
		_location = _home;
		return (true);
	}
	return (false);
}

bool Federation::Starfleet::Ship::move(Destination d)
{
	WarpSystem::QuantumReactor *iz = _core->checkReactor();

	if (d != _location && iz->isStable()) {
		_location = d;
		return (true);
	}
	return (false);
}

Federation::Starfleet::Captain::Captain(std::string name)
	: _name(name)
{}

Federation::Starfleet::Captain::~Captain()
{}

std::string Federation::Starfleet::Captain::getName()
{
	return _name;
}

int Federation::Starfleet::Captain::getAge()
{
	return _age;
}

void Federation::Starfleet::Captain::setAge(int age)
{
	_age = age;
}

Federation::Ship::Ship(int length, int width, std::string name)
	: _length(length),
	_width(width),
	_name(name),
	_maxWarp(1),
	_location(VULCAN),
	_home(VULCAN)
{
	std::cout << "The independant ship " << name << " just finished";
	std::cout << " its construction.";
	std::cout << std::endl << "It is " << length << " m in length and ";
	std::cout << width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
	_core = core;
	std::cout << _name;
	std::cout << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
	WarpSystem::QuantumReactor *iz = _core->checkReactor();

	std::cout << _name << ": The core is ";
	if (iz->isStable())
		std::cout << "stable";
	else
		std::cout << "unstable";
	std::cout << " at the time." << std::endl;
}

bool Federation::Ship::move(int warp, Destination d)
{
	WarpSystem::QuantumReactor *iz = _core->checkReactor();

	if (warp <= _maxWarp && d != _location && iz->isStable()) {
		_location = d;
		return (true);
	}
	return (false);
}

bool Federation::Ship::move(int warp)
{
	WarpSystem::QuantumReactor *iz = _core->checkReactor();

	if (warp <= _maxWarp && _home != _location && iz->isStable()) {
		_location = _home;
		return (true);
	}
	return (false);
}

bool Federation::Ship::move(Destination d)
{
	WarpSystem::QuantumReactor *iz = _core->checkReactor();

	if (d != _location && iz->isStable()) {
		_location = d;
		return (true);
	}
	return (false);
}

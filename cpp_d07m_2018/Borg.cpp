/*
** EPITECH PROJECT, 2018
** Borg.cpp
** File description:
** <..>
*/

#include "Borg.hpp"

Borg::Ship::Ship()
	: _side(300),
	_maxWarp(9),
	_location(UNICOMPLEX),
	_home(UNICOMPLEX)
{
	std::cout << "We are the Borgs. Lower your shields and surrender"
		"yourselves unconditionally." << std::endl << "Your biol"
		"ogical characteristics and technologies will be assimil"
		"ated." << std::endl << "Resistence is futile." << std::endl;
}

Borg::Ship::~Ship()
{}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
	_core = core;
}

void Borg::Ship::checkCore()
{
	WarpSystem::QuantumReactor *iz = _core->checkReactor();

	if (iz->isStable())
		std::cout << "Everything is in order." << std::endl;
	else
		std::cout << "Critical failure imminent" << std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
	WarpSystem::QuantumReactor *iz = _core->checkReactor();

	if (warp <= _maxWarp && d != _location && iz->isStable()) {
		_location = d;
		return (true);
	}
	return (false);
}

bool Borg::Ship::move(int warp)
{
	WarpSystem::QuantumReactor *iz = _core->checkReactor();

	if (warp <= _maxWarp && _home != _location && iz->isStable()) {
		_location = _home;
		return (true);
	}
	return (false);
}

bool Borg::Ship::move(Destination d)
{
	WarpSystem::QuantumReactor *iz = _core->checkReactor();

	if (d != _location && iz->isStable()) {
		_location = d;
		return (true);
	}
	return (false);
}

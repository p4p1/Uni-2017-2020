/*
** EPITECH PROJECT, 2018
** WarpSystem.cpp
** File description:
** <..>
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor()
	: _stability(true)
{}

WarpSystem::QuantumReactor::~QuantumReactor()
{}

bool WarpSystem::QuantumReactor::isStable()
{
	return _stability;
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
	_stability = stability;
}

WarpSystem::Core::Core(WarpSystem::QuantumReactor *coreReactor)
	: _coreReactor(coreReactor)
{}

WarpSystem::Core::~Core()
{}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
	return _coreReactor;
}

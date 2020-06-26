/*
** EPITECH PROJECT, 2018
** SickKoalaList.cpp
** File description:
** <..>
*/

#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *koala)
{
	_begin = malloc(sizeof(List));
	_end = _begin;
	_current = _begin;
	_begin->next = NULL;
	_begin->koala = koala;
}

SickKoalaList::~SickKoalaList()
{
	List	*cu = _begin;
	while (_begin != NULL) {
		cu = _begin;
		_begin = _begin->next;
		free(cu);
	}
}

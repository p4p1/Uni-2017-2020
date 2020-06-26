/*
** EPITECH PROJECT, 2017
** SickKoalaList.hpp
** File description:
** <..>
*/

#ifndef SICKKOALALIST_HPP_
#define SICKKOALALIST_HPP_

#include "SickKiala.hpp"

typedef struct list_s {
	struct list_s	*nest;
	SickKoala	*koala;
} List;

class SickKoalaList {
	public:
		SickKoalaList(SickKoala *koala);
		~SickKoalaList();
	private:
		List	*_begin;
		List	*_current;
		List	*_end;
};

#endif

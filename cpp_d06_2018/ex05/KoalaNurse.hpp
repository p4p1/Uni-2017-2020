/*
** EPITECH PROJECT, 2017
** KoalaNurse.hpp
** File description:
** <..>
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

#include "SickKoala.hpp"

class KoalaNurse {
	public:
		KoalaNurse(int id);
		~KoalaNurse();
		void giveDrug(std::string drug, SickKoala *patient);
		std::string readReport(std::string file_name);
		void timeCheck();
		int getID();

	private:
		int	_id;
};

#endif

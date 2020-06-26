/*
** EPITECH PROJECT, 2017
** KoalaDoctor.hpp
** File description:
** <..>
*/

#ifndef KOALA_DOCTOR_HPP_
#define KOALA_DOCTOR_HPP_

#include "KoalaNurse.hpp"
#include "SickKoala.hpp"

class KoalaDoctor {
	public:
		KoalaDoctor(std::string name);
		~KoalaDoctor();
		void diagnose(SickKoala *patient);
		void timeCheck();

	private:
		std::string _name;
};

#endif

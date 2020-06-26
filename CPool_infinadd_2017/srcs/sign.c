/*
** EPITECH PROJECT, 2017
** sign.c
** File description:
** processing the sign
*/

#include "infin_add.h"

int display_sign(char **v1, char **v2)
{
	int	flag = 0;

	if (**v1 == '-' && my_strlen(*v1) > my_strlen(*v2)) {
		flag = 1;
	}
	if (**v2 == '-' && my_strlen(*v2) > my_strlen(*v1)) {
		flag = 1;
	}
	if (**v1 == '-') {
		*v1 += 1;
	}
	if (**v2 == '-') {
		*v2 += 1;
	}
	return (flag);
}

int get_sign(char *str)
{
	if (*str == '-')
		return (-1);
	return (1);
}


/*
** EPITECH PROJECT, 2017
** char_to_int.c
** File description:
** convert a char to an int and an int to a char
*/

#include "infin_add.h"

int ch_to_i(char ch)
{
	if (ch < '0' || ch > '9')
		return (0);
	return (ch - '0');
}

int i_to_ch(int i)
{
	if (i < 0 || i > 9)
		return (0);
	return (i + '0');
}

/*
** EPITECH PROJECT, 2017
** string.c
** File description:
** <..>
*/

#include "navy.h"

int is_not_no(char ch)
{
	if (ch <= '8' && ch >= '1')
		return (0);
	return (1);
}

int is_not_ltr(char ch)
{
	if (ch <= 'H' && ch >= 'A')
		return (0);
	return (1);
}

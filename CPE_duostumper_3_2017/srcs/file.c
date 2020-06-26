/*
** EPITECH PROJECT, 2017
** file.c
** File description:
** <..>
*/

#include "cesar.h"

void write_char(int fp, char ch)
{
	write(fp, &ch, 1);
}

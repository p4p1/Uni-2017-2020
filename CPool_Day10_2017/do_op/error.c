/*
** EPITECH PROJECT, 2017
** error.c
** File description:
** error funcitons
*/

#include "do_op.h"

void my_putchar_err(char c)
{
	write(2, &c, 1);
}

void my_putstr_err(char *str)
{
	while (*str != '\0')
		my_putchar_err(*str++);
}

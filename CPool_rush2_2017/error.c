/*
** EPITECH PROJECT, 2017
** error.c
** File description:
** functions to write to stderr
*/

#include <unistd.h>

#include "include/rush2.h"

void my_putchar_err(char c)
{
	write(2, &c, 1);
}

void my_putstr_err(char *str)
{
	while (*str != '\0')
		my_putchar_err(*str++);
}

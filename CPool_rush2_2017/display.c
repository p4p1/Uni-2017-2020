/*
** EPITECH PROJECT, 2017
** display.c
** File description:
** all display_function
*/

#include "include/rush2.h"

void display_single_occurence(char letter, int num, int percentage)
{
	my_putchar(letter);
	my_putchar(':');
	my_put_nbr(num);
	my_putstr(" (");
	my_put_nbr(percentage / 1000);
	my_putchar('.');
	my_put_nbr((percentage % 1000) / 10 );
	if ((percentage % 1000) / 10 == 0)
		my_putchar('0');
	my_putstr("%)\n");
}

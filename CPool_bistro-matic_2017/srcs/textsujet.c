/*
** EPITECH PROJECT, 2017
** textsujet.c
** File description:
** print the usage to the screen
*/

#include "bistro.h"

static char bsnt(void)
{
	my_putchar('\n');
	my_putchar('\t');
	return(0);
}

static int usage(char *name)
{
	my_putstr("USAGE");
	bsnt();
	my_putchar('\t');
	my_putchar('\t');
	my_putstr(name);
	my_putstr(" base operators size_read");
	my_putchar('\n');
	my_putchar('\n');
	return(0);
}

static int description(void)
{
	my_putstr("DESCRIPTION");
	bsnt();
	my_putstr("base");
	my_putchar('\t');
	my_putchar('\t');
	my_putstr("all the symbols of the base");
	bsnt();
	my_putstr("operators");
	my_putchar('\t');
	my_putstr("the symbole for the parentheses and the 5 operators");
	bsnt();
	my_putstr("size_read");
	my_putchar('\t');
	my_putstr("number of characters to be read");
	return(0);
}

int usage_description(char *name)
{
	usage(name);
	description();
	return (0);
}

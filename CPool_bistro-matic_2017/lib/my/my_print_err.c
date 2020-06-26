/*
** EPITECH PROJECT, 2017
** <..>
** File description:
** <...>
*/
#include "my.h"

void my_print_err(char *c)
{
	write (2, c, my_strlen(c));
}

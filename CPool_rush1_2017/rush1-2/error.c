/*
** EPITECH PROJECT, 2017
** error.c
** File description:
** error functions
*/

#include <unistd.h>

void my_putchar_err(char c)
{
	write(2, &c, 1);
}

void my_putstr_err(char const *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		my_putchar_err(str[i]);
		i += 1;
	}
}

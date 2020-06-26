/*
** EPITECH PROJECT, 2017
** str_util.c
** File description:
** utility file for string display
*/

#include "hidenp.h"

static void my_putchar(char ch)
{
	write(1, &ch, 1);
}

int my_strlen(char *str)
{
	int	len = 0;

	if (str == NULL)
		return (0);
	while (str[len])
		len++;
	return (len);
}

void my_puts(char *str)
{
	write(1, str, my_strlen(str));
	my_putchar('\n');
}

void my_puts_err(char *str)
{
	write(2, str, my_strlen(str));
}

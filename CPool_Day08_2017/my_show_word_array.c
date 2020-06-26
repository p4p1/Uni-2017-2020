/*
** EPITECH PROJECT, 2017
** my_show_word_array
** File description:
** <..>
*/

#include <stdio.h>

#include "include/libmy.h"

void my_putchar(char c);

int my_show_word_array(char * const *tab)
{
	int	i = 0;

	if (tab == 0)
		return (-1);
	while (*(tab+i) != 0) {
		my_putstr(*(tab+i));
		my_putchar('\n');
		++i;
	}
	return (0);
}

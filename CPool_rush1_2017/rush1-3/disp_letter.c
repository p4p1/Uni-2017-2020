/*
** EPITECH PROJECT, 2017
** disp_letter.c
** File description:
** functions that display n times a given letter
*/
#include <stdio.h>

void my_putchar(char c);

void disp_single_line(char ch, int x, int y)
{
	int	i = 0;
	int	n = y;

	if (y == 1)
		n = x;
	while (i < n) {
		my_putchar(ch);
		if (x == 1)
			my_putchar('\n');
		i += 1;
	}
}

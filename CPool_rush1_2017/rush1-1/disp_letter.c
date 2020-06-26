/*
** EPITECH PROJECT, 2017
** disp_letter.c
** File description:
** functions that display n times a given letter
*/
#include <stdio.h>

void my_putchar(char c);

void disp_dash(int x, int n)
{
	int	i = 0;

	while (i++ < (n-2)) {
		if (x == 1) {
			my_putchar('|');
			my_putchar('\n');
		} else {
			my_putchar('-');
		}
	}
}

int disp_single_line(int x, int y)
{
	int	n = y;

	if (x == 1 && y == 1) {
		my_putchar('o');
		my_putchar('\n');
		return (0);
	}
	my_putchar('o');
	if (x == 1)
		my_putchar('\n');
	if (y == 1)
		n = x;
	disp_dash(x, n);
	my_putchar('o');
	my_putchar('\n');
	return (0);
}

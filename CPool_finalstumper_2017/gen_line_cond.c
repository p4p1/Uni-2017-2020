/*
** EPITECH PROJECT, 2017
** gen_line_cond.c
** File description:
** gen_line_condition generator
*/

#include "rush3.h"

void rush1(char *str, int size, int height, int len)
{
	if (size == 1 && (len == 0 || len == (height - 1))) {
		str[0] = 'o';
		str[1] = '\0';
	} else if (size == 1 && (len != 0 || len != (height -1))) {
		str[0] = '|';
		str[1] = '\0';
	}
}

void rush2(char *str, int size, int height)
{
	int	i = 0;

	if (height == 1) {
		while (i < size) {
			str[i] = '*';
			i++;
		}
	}
	if (size == 1) {
		str[0] = '*';
		str[1] = '\0';
	}
}

void rushB(char *str, int size, int height)
{
	int	i = 0;

	if (height == 1 || size == 1) {
		while (i < size) {
			str[i] = 'B';
			i++;
		}
	}
	if (size == 1) {
		str[0] = 'B';
		str[1] = '\0';
	}
}

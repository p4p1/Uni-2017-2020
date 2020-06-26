/*
** EPITECH PROJECT, 2017
** my_strncmp.c
** File description:
** compare to string up to n size
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
	int	i = 0;

	while (*s1 == *s2 && i <= n) {
		++s1;
		++s2;
		++i;
	}
	return (*s1 - *s2);
}

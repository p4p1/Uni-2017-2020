/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** compare 2 string return difference of 2
*/

#include "my.h"

static int get_str_len(char const *str)
{
	int	len = 0;

	while (*(str + len) != '\0')
		len++;
	return (len);
}

int my_strcmp(char const *s1, char const *s2)
{
	int	len_s1 = get_str_len(s1);
	int	len_s2 = get_str_len(s2);
	int	len = (len_s1 < len_s2) ? len_s1 : len_s2;
	int	i = 0;

	while (*s1 == *s2 && i < len) {
		++s1;
		++s2;
		++i;
	}
	return (*s1 - *s2);
}

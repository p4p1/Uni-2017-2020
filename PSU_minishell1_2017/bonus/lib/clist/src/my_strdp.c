/*
** EPITECH PROJECT, 2017
** my_strdp.c
** File description:
** dump a string on the heap
*/

#include "clist.h"

char *my_strdp(char const *str)
{
	char	*t_str = 0;
	int	len = 0;

	if (str == 0)
		return (0);
	while (str[len] != '\0')
		len++;
	t_str = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	while (str[len] != '\0') {
		t_str[len] = str[len];
		len++;
	}
	t_str[len] = '\0';
	return (t_str);
}

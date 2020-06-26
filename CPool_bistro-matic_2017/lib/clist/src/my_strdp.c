/*
** EPITECH PROJECT, 2017
** my_strdp.c
** File description:
** dump a string on the heap
*/

#include "clist.h"

char *my_strdp(char const *str)
{
	char	*src;
	int	i = 0;
	int	len = 0;

	if (str == 0)
		return (0);
	while (str[len] != '\0')
		len++;
	src = (char *)malloc(sizeof(char) * (len + 1));
	while (str[i] != '\0') {
		src[i] = str[i];
		++i;
	}
	src[i] = '\0';
	return (src);

}

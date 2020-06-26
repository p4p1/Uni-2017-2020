/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** allocate given string to memory.
*/

#include <stdlib.h>

#include "include/libmy.h"

void my_putchar(char c);

char *my_strdup(char const *src)
{
	char	*str;

	if (str == 0)
		return (0);
	str = (char *)malloc(sizeof(char) * my_strlen(src));
	my_strcpy(str, src);
	return (str);
}


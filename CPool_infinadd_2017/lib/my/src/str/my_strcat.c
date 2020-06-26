/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** the my_strcat function file, concat 2 different strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
	int	i = 0;
	int	c = 0;

	while (*(dest + c) != '\0')
		c++;
	while (*(src + i) != '\0') {
		*(dest + (c + i)) = *(src + i);
		++i;
	}
	return (dest);
}

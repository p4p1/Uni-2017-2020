/*
** EPITECH PROJECT, 2017
** count.c
** File description:
** <..>
*/

#include "minishell2.h"

char *my_strcpy_alphanum(char *dest, char const *src)
{
	int	i = 0;

	if (dest == 0 || src == 0)
		return (0);
	while (*src != '\0') {
		if ((*src >= 'a' && *src <= 'z') ||
				(*src >= 'A' && *src <= 'Z') || (*src >= '0' &&
				*src <= '9') || *src == '_') {
			*(dest + i++) = *src++;
		} else {
			return (NULL);
		}
	}
	*(dest + i) = '\0';
	return (dest);
}

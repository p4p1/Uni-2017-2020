/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** allocate given string to memory.
*/

#include "my.h"

char *my_strdup(char const *src)
{
	char	*str = NULL;
	int	i = 0;

	if (src == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (my_strlen(src) + 1));
	if (str == NULL)
		return (NULL);
	while (src[i] != '\0') {
		str[i] = src[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}

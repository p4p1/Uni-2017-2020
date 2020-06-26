/*
** EPITECH PROJECT, 2017
** my_strdup_ln.c
** File description:
** <..>
*/

#include "my.h"

char *my_strdup_ln(char const *src, int pos)
{
	char	*str = NULL;
	int	i = 0;

	if (src == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (pos + 1));
	while (src[i] != '\0' && i < pos) {
		str[i] = src[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}

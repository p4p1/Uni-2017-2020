/*
** EPITECH PROJECT, 2017
** <.>
** File description:
** <..>
*/
#include "my.h"

int my_strlen(char const *str)
{
	int	i = 0;

	while (str[i])
		++i;
	return (i);
}
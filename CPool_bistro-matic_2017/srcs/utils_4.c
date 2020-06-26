/*
** EPITECH PROJECT, 2017
** utils_4.c
** File description:
** utils 4 function
*/

#include "bistro.h"

int len(char *str)
{
	int	i = 0;
	while (str[i])
		++i;
	return (i);
}

char *dump_z(char *str, char const *base)
{
	int	i = 0;

	if (my_strlen(str) > 1) {
		while (str[i] == base[0])
			i++;
		return (str + i);
	} else {
		return (str);
	}
}

void zero_exception(void)
{
	my_putstr(ERROR_MSG);
	exit(OP_DIV_IDX);
}

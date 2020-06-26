/*
** EPITECH PROJECT, 2017
** utils.c
** File description:
** utils functions
*/
#include "bistro.h"

void my_memset(char *str, int size)
{
	for (int i = 0; i < size; ++i) {
		str[i] = 0;
	}
}

char to_base(int c, char const *base)
{
	return (base[c]);
}

int  from_base(char c, char const *base)
{
	int	i;

	for (i = 0; base[i] && base[i] != c; ++i);
	if (base[i] == 0)
		return (0);
	return (i);
}

char *str_malloc(char *s1, char *s2)
{
	char	*result = NULL;

	if (my_strlen(s1) > my_strlen(s2)) {
		result = rb_malloc(sizeof(char) * (my_strlen(s1) + 3));
		if (result == NULL)
			return (NULL);
	} else {
		result = rb_malloc(sizeof(char) * (my_strlen(s2) + 3));
		if (result == NULL)
			return (NULL);
	}
	return (result);
}

int check_neg(char const *str, char op)
{
	int	check = 1;
	int	i = 0;

	while (str[i]) {
		if (str[i] == op)
			check *= -1;
		++i;
	}
	return (check);
}

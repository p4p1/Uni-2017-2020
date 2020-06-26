/*
** EPITECH PROJECT, 2018
** fract.c
** File description:
** ..
*/

#include "fractals.h"

char *my_return_replace(char *buff)
{
	int i = 0;

	while (buff[i++] != '\0') {
		if (buff[i] == '@')
			buff[i] = '\n';
	}
	return (buff);
}

char *my_fract_replace(char *buff, char *chain1, char *chain2)
{
	int	i = 0;
	int	j = 0;
	char	*copy = my_strdup(buff);

	if (copy == NULL)
		return (NULL);
	while (copy[i] != '\0') {
		if (chain1[i] == '#') {
			buff = expand_buf(buff, copy, &j);
		} else if (chain1[i] == '.') {
			buff = expand_buf(buff, chain2, &j);
		}
		j++;
		i++;
	}
	return (buff);
}

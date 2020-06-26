/*
** EPITECH PROJECT, 2017
** expander.c
** File description:
** <..>
*/

#include "fractals.h"

char *expand_buf(char *buff, char *ins, int *pos)
{
	char	*tmp = malloc(sizeof(char) *
			(my_strlen(buff) + my_strlen(ins) + 1));
	int	i = 0;
	int	j = 0;
	int	inc = 0;

	if (tmp == NULL)
		return (NULL);
	while (i < *pos && buff[i]) {
		tmp[i] = buff[i];
		++i;
	}
	j = i;
	for (inc = 0; ins[inc]; inc++)
		tmp[i++] = ins[inc];
	*pos += inc;
	while (buff[j])
		tmp[i++] = buff[j++];
	tmp[i] = '\0';
	return (tmp);
}

/*
** EPITECH PROJECT, 2017
** <..>
** File description:
** <...>
*/
#include "my.h"

void	*rb_malloc(int size)
{
	void	*str;

	if ((str = malloc(size)) == NULL)
		return (NULL);
	return (str);
}
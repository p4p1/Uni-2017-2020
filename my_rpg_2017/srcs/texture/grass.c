/*
** EPITECH PROJECT, 2017
** grass.c
** File description:
** <..>
*/

#include "size.h"

sfIntRect *grass_1(void)
{
	sfIntRect *size = malloc(sizeof(sfIntRect));

	if (size == NULL)
		return (NULL);
	size->top = 240;
	size->left = 16;
	size->height = 47;
	size->width = 47;
	return (size);
}

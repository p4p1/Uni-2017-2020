/*
** EPITECH PROJECT, 2017
** building.c
** File description:
** <..>
*/

#include "size.h"

sfIntRect *poke_center(void)
{
	sfIntRect *size = malloc(sizeof(sfIntRect));

	if (size == NULL)
		return (NULL);
	size->top = 558;
	size->left = 1087;
	size->height = 97;
	size->width = 124;
	return (size);
}

sfIntRect *poke_market(void)
{
	sfIntRect *size = malloc(sizeof(sfIntRect));

	if (size == NULL)
		return (NULL);
	size->top = 653;
	size->left = 1087;
	size->height = 97;
	size->width = 124;
	return (size);
}

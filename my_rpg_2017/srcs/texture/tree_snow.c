/*
** EPITECH PROJECT, 2017
** tree_snow.c
** File description:
** <..>
*/

#include "my_rpg.h"

sfIntRect *tree_snow_1(void)
{
	sfIntRect *size = malloc(sizeof(sfIntRect));

	if (size == NULL)
		return (NULL);
	size->top = 0;
	size->left = 210;
	size->height = 46;
	size->width = 46;
	return (size);
}

sfIntRect *tree_snow_2(void)
{
	sfIntRect *size = malloc(sizeof(sfIntRect));

	if (size == NULL)
		return (NULL);
	size->top = 0;
	size->left = 258;
	size->height = 46;
	size->width = 46;
	return (size);
}

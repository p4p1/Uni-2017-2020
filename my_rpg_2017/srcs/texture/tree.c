/*
** EPITECH PROJECT, 2017
** tree.c
** File description:
** <..>
*/

#include "size.h"

sfIntRect *tree_1(void)
{
	sfIntRect *size = malloc(sizeof(sfIntRect));

	if (size == NULL)
		return (NULL);
	size->top = 4;
	size->left = 18;
	size->height = 46;
	size->width = 46;
	return (size);
}

sfIntRect *tree_2(void)
{
	sfIntRect *size = malloc(sizeof(sfIntRect));

	if (size == NULL)
		return (NULL);
	size->top = 0;
	size->left = 63;
	size->height = 50;
	size->width = 50;
	return (size);
}

sfIntRect *tree_3(void)
{
	sfIntRect *size = malloc(sizeof(sfIntRect));

	if (size == NULL)
		return (NULL);
	size->top = 0;
	size->left = 111;
	size->height = 50;
	size->width = 50;
	return (size);
}

sfIntRect *tree_4(void)
{
	sfIntRect *size = malloc(sizeof(sfIntRect));

	if (size == NULL)
		return (NULL);
	size->top = 0;
	size->left = 161;
	size->height = 50;
	size->width = 50;
	return (size);
}

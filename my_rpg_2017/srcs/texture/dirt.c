/*
** EPITECH PROJECT, 2017
** dirt.c
** File description:
** <..>
*/

#include "size.h"

sfIntRect *dirt_1(void)
{
	sfIntRect *size = malloc(sizeof(sfIntRect));

	if (size == NULL)
		return (NULL);
	size->top = 240;
	size->left = 256;
	size->height = 47;
	size->width = 47;
	return (size);
}

sfIntRect *dirt_2(void)
{
	sfIntRect *size = malloc(sizeof(sfIntRect));

	if (size == NULL)
		return (NULL);
	size->top = 240;
	size->left = 352;
	size->height = 47;
	size->width = 47;
	return (size);
}

sfIntRect *dirt_3(void)
{
	sfIntRect *size = malloc(sizeof(sfIntRect));

	if (size == NULL)
		return (NULL);
	size->top = 240;
	size->left = 400;
	size->height = 47;
	size->width = 47;
	return (size);
}

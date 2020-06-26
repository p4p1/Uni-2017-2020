/*
** EPITECH PROJECT, 2017
** colision.c
** File description:
** <..>
*/

#include "my_runner.h"

int colision(struct __entity__ *en1, struct __entity__ *en2)
{
	sfFloatRect	b_en1;
	sfFloatRect	b_en2;

	if (en1 == NULL || en2 == NULL)
		return (-1);
	b_en1 = sfSprite_getGlobalBounds(en1->sprite[en1->actual_frame]);
	b_en2 = sfSprite_getGlobalBounds(en2->sprite[en2->actual_frame]);
	b_en1.width -= 30;
	if (en1->pos.x < en2->pos.x + b_en2.width && en1->pos.x + b_en1.width >
			en2->pos.x && en1->pos.y < en2->pos.y + b_en2.height &&
			en1->pos.y + b_en1.height > en2->pos.y)
		return (1);
	return (0);
}

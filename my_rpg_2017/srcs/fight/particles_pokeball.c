/*
** EPITECH PROJECT, 2018
** my_rpog
** File description:
** pokeball particles
*/

#include <string.h>
#include "my_rpg.h"

partBuffer *newPartBuffer(int size)
{
	partBuffer *this;
	const size_t size_m = (sizeof(partBuffer) +
		sizeof(sfVertex) * size * 4);
	void *ptn = malloc(size_m);

	if (ptn == NULL)
		return (NULL);
	memset(ptn, 0, size_m);
	this = (partBuffer*)(ptn);
	this->size = size;
	this->vertex = (sfVertex*)(ptn + sizeof(partBuffer));
	return (this);
}

void setpart(partBuffer *this, sfVector2f pos, int id)
{
	if (id >= this->size)
		return ;
	this->vertex[id].position = (sfVector2f){pos.x - 10, pos.y - 10};
	this->vertex[id + 1].position = (sfVector2f){pos.x + 10, pos.y - 10};
	this->vertex[id + 2].position = (sfVector2f){pos.x + 10, pos.y + 10};
	this->vertex[id + 3].position = (sfVector2f){pos.x - 10, pos.y + 10};
	this->vertex[id].color = sfRed;
	this->vertex[id + 1].color = sfBlack;
	this->vertex[id + 2].color = sfRed;
	this->vertex[id + 3].color = sfBlack;
	this->vertex[id].color.a = 50;
	this->vertex[id + 1].color.a = 50;
	this->vertex[id + 2].color.a = 50;
	this->vertex[id + 3].color.a = 50;
}

void drawpartbuffer(partBuffer *this, sfRenderWindow *window)
{
	sfRenderWindow_drawPrimitives(window, this->vertex, this->size * 4, sfQuads, NULL);
	sfRenderWindow_display(window);
}

void particles_pokeball(sfRenderWindow *window)
{
	int i = 0;
	partBuffer *buffer = newPartBuffer(2000);

	srand(time(NULL));
	for (int j = 0; j < 8; j++)
		setpart(buffer, (sfVector2f){175, 460}, j * 4);
	while (i != 8) {
		updatePartBuffer(buffer);
		drawpartbuffer(buffer, window);
		i++;
		wait_for(0.05);
	}
}

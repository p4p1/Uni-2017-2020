/*
** EPITECH PROJECT, 2018
** aze
** File description:
** zae
*/

#include "my_rpg.h"

void updatePartBuffer3(partBuffer *this)
{
	int i = 20;

	this->vertex[16].position.x -= i;
	this->vertex[17].position.x -= i;
	this->vertex[18].position.x -= i;
	this->vertex[19].position.x -= i;
	this->vertex[20].position.y += i;
	this->vertex[21].position.y += i;
	this->vertex[22].position.y += i;
	this->vertex[23].position.y += i;
	this->vertex[24].position.x += i;
	this->vertex[25].position.x += i;
	this->vertex[26].position.x += i;
	this->vertex[27].position.x += i;
	this->vertex[28].position.y -= i;
	this->vertex[29].position.y -= i;
	this->vertex[30].position.y -= i;
	this->vertex[31].position.y -= i;
}

void updatePartBuffer2(partBuffer *this)
{
	int i = 20;

	this->vertex[8].position.x -= i;
	this->vertex[9].position.x -= i;
	this->vertex[10].position.x -= i;
	this->vertex[11].position.x -= i;
	this->vertex[8].position.y += i;
	this->vertex[9].position.y += i;
	this->vertex[10].position.y += i;
	this->vertex[11].position.y += i;
	this->vertex[12].position.x -= i;
	this->vertex[13].position.x -= i;
	this->vertex[14].position.x -= i;
	this->vertex[15].position.x -= i;
	this->vertex[12].position.y -= i;
	this->vertex[13].position.y -= i;
	this->vertex[14].position.y -= i;
	this->vertex[15].position.y -= i;
	updatePartBuffer3(this);
}

void updatePartBuffer(partBuffer *this)
{
	int i = 20;

	this->vertex[0].position.x += i;
	this->vertex[1].position.x += i;
	this->vertex[2].position.x += i;
	this->vertex[3].position.x += i;
	this->vertex[0].position.y += i;
	this->vertex[1].position.y += i;
	this->vertex[2].position.y += i;
	this->vertex[3].position.y += i;
	this->vertex[4].position.x += i;
	this->vertex[5].position.x += i;
	this->vertex[6].position.x += i;
	this->vertex[7].position.x += i;
	this->vertex[4].position.y -= i;
	this->vertex[5].position.y -= i;
	this->vertex[6].position.y -= i;
	this->vertex[7].position.y -= i;
	updatePartBuffer2(this);
}

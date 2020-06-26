/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** all about character
*/

#include "my_rpg.h"

void create_character(character_t *hero, object_t *obj, int x, int y)
{
	hero->trainer = sfRectangleShape_create();
	hero->pos.x = 960;
	hero->pos.y = 540;
	hero->size.x = 45;
	hero->size.y = 60;
	hero->pokedollards = 3000;
	hero->clock = sfClock_create();
	sfRectangleShape_setPosition(hero->trainer, hero->pos);
	hero->pos_map.x = x;
	hero->pos_map.y = y;
	sfRectangleShape_setSize(hero->trainer, hero->size);
	sfRectangleShape_setTexture(hero->trainer, obj->texture, sfTrue);
	sfRectangleShape_setTextureRect(hero->trainer, obj->actual_state);
}

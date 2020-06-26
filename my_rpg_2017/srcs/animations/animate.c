/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** animation handler
*/

#include "my_rpg.h"

object_t *create_object(char const *path, int nb_animation, sfIntRect rect,
			int gap)
{
	object_t *new_obj = malloc(sizeof(*new_obj));

	new_obj->texture = sfTexture_createFromFile(path, NULL);
	if (new_obj->texture == NULL || new_obj == NULL)
		return (NULL);
	new_obj->actual_state = rect;
	new_obj->gap = gap;
	new_obj->nb_anim[0] = 1;
	new_obj->nb_anim[1] = nb_animation;
	new_obj->clock = sfClock_create();
	if (new_obj->clock == NULL)
		return (NULL);
	return (new_obj);
}

int animate(object_t *obj, character_t *hero)
{
	sfTime time = sfClock_getElapsedTime(obj->clock);
	int milliseconds = sfTime_asMilliseconds(time);

	if (milliseconds >= 100) {
		if (obj->nb_anim[0] != obj->nb_anim[1]) {
			obj->actual_state.left += obj->gap;
			obj->nb_anim[0] += 1;
		} else {
			obj->actual_state.left = 0;
			obj->nb_anim[0] = 1;
		}
		sfRectangleShape_setTextureRect(hero->trainer,
			obj->actual_state);
		sfClock_restart(obj->clock);
	}
	return (0);
}

object_t *create_hero_animation(character_t *hero, int x, int y)
{
	char *path = "./res/texture/movement.png";
	object_t *new_object = NULL;
	sfIntRect rect;

	rect.left = 0;
	rect.top = 0;
	rect.width = 45;
	rect.height = 50;
	new_object = create_object(path, 3, rect, 63);
	create_character(hero, new_object, x, y);
	return (new_object);
}

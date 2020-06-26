/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** music engine
*/

#include <stdlib.h>
#include "../../include/sound_engine.h"

int music_change(music_t *music1, music_t *music2)
{
	sfTime time = sfClock_getElapsedTime(music1->clock);
	float seconds = sfTime_asSeconds(time);

	if (seconds >= 1) {
		music1->volume -= 10;
		music2->volume += 10;
		sfMusic_setVolume(music1->music, music1->volume);
		sfMusic_setVolume(music2->music, music2->volume);
		sfClock_restart(music1->clock);
	}
	if (music1->volume <= 0)
		return (1);
	return (0);
}

music_t *create_music(sfMusic *music)
{
	sfClock *clock = sfClock_create();
	float volume = 0;
	music_t *new = malloc(sizeof(*new));

	if (new == NULL || clock == NULL)
		return (NULL);
	new->music = music;
	new->clock = clock;
	new->volume = volume;
	return (new);
}

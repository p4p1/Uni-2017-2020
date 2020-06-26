/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** sound_engine
*/

#ifndef SOUND_ENG_
#define SOUND_ENG_

#include "my_rpg.h"

typedef struct s_music music_t;

struct s_music
{
	sfMusic *music;
	sfClock *clock;
	float volume;
};

#endif /* SOUND_ENG_ */

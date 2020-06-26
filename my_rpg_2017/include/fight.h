/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** fight . h
*/


#ifndef FIGHT_
#define FIGHT_

#include <SFML/Config.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

typedef unsigned int uint;
typedef struct s_partBuffer
{
	sfVertex *vertex;
	uint size;
} partBuffer;

partBuffer *newPartBuffer(int size);
void updatePartBuffer(partBuffer *this);

extern const char *names[];

void display_run_message(sfRenderWindow *window);
sfText *create_txt(sfVector2f pos, char *name, int char_size);
void display_background(sfRenderWindow *window);
void display_names(sfRenderWindow *window, int id_ally, int id_ennemy);
void display_pokemons(sfRenderWindow *window, sfSprite *ally, sfSprite *enemy);
int display_player_throwing_pokeball(sfRenderWindow *window, int a);
int get_user_click(sfRenderWindow *window, sfEvent *event);
void pokeball_turning(sfRenderWindow *window, int a);
void particles_pokeball(sfRenderWindow *window);
void wait_for(float a);
void display_txt_fight(sfRenderWindow *window, sfText *txt);
sfSprite *get_pkm_sprite(int ID_pkm, char *file);

#endif /* FIGHT_ */

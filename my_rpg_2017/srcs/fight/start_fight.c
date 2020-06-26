/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** start the fight
*/

#include "my_rpg.h"

static void dis_var(sfRenderWindow *window, pokemon_t *ally, pokemon_t *ennemy)
{
	display_txt_fight(window, ally->sfname);
	display_txt_fight(window, ennemy->sfname);
	display_txt_fight(window, ally->sflvl);
	display_txt_fight(window, ennemy->sflvl);
	display_pokemons(window, ally->sfsprite, ennemy->sfsprite);
}

static int scene_fight(game_t *gm, pokemon_t *ennemy, pokemon_t *ally, int a)
{
	if (a < 15) {
		display_player_throwing_pokeball(gm->wd, a);
		a++;
	} else {
		if (actual_scene == 2 || actual_scene == 5)
			dis_var(gm->wd, ally, ennemy);
	}
	return (0);
}

int start_fight(gui_t **guis, game_t *gm)
{
	static int a = 0;
	sfIntRect area = {2919, 1000, 970, 820};
	sfTexture *text = sfTexture_createFromFile
		("res/texture/Interface_spritesheet.png", &area);
	sfSprite *sprite_bg = sfSprite_create();
	int random = rand() % 4 + 3;

	sfSprite_setTexture(sprite_bg, text, sfTrue);
	set_ally(gm->wd, gm->hero->pokemon[0], gm->hero->pokemon[0]->id);
	set_ennemy(gm->wd, gm->pokemons[random], gm->pokemons[random]->id);
	sfRenderWindow_clear(gm->wd, sfWhite);
	while (actual_scene != -1) {
		scene_fight(gm, gm->pokemons[random], gm->hero->pokemon[0], a);
		sfRenderWindow_display(gm->wd);
		sfRenderWindow_clear(gm->wd, sfWhite);
		sfRenderWindow_drawSprite(gm->wd, sprite_bg, NULL);
		if (actual_scene == 4)
			stat_menu(guis, gm, gm->hero->pokemon[0]);
		else
			display_menu(guis, gm);
		a++;
	}
	a = 0;
	return (0);
}

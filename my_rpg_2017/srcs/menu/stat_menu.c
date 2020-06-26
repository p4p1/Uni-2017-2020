/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** statistics menu for pokemons
*/

#include "my_rpg.h"

static void set_other_stats(pokemon_t *pokemon, sfText **stats, sfVector2f pos)
{
	pos.x += 80;
	pos.y += 125;
	stats[3] = create_txt(pos, my_itoa(pokemon->attack), 40);
	pos.y += 100;
	stats[4] = create_txt(pos, my_itoa(pokemon->defense), 40);
	pos.y += 80;
	stats[5] = create_txt(pos, my_itoa(pokemon->att_spe), 40);
	pos.y += 100;
	stats[6] = create_txt(pos, my_itoa(pokemon->def_spe), 40);
	pos.y += 90;
	stats[7] = create_txt(pos, my_itoa(pokemon->speed), 40);
}

static sfText **set_stats(pokemon_t *pokemon)
{
	sfText **stats = malloc(sizeof(sfText *) * 8);
	sfVector2f pos = {130, 135};

	stats[0] = create_txt(pos, pokemon->name, 40);
	pos.y = 250;
	stats[1] = create_txt(pos, my_strdupcat("Nv ", my_itoa(pokemon->lvl)), 40);
	pos.y = 205;
	pos.x = 1495;
	stats[2] = create_txt(pos, my_strdupcat(my_strdupcat(my_itoa
			(pokemon->hp[0]), "/"), my_itoa(pokemon->hp[1])), 40);
	set_other_stats(pokemon, stats, pos);
	return (stats);
}

static void event(game_t *gm, gui_t **guis)
{
	while (sfRenderWindow_pollEvent(gm->wd, &gm->event)) {
		if (gm->event.type == sfEvtClosed)
			sfRenderWindow_close(gm->wd);
		if (gm->event.key.code == sfKeyEscape)
			actual_scene = -1;
	}
}

void stat_menu(gui_t **guis, game_t *gm, pokemon_t *pokemon)
{
	sfText **stats = set_stats(pokemon);
	while (actual_scene == 4 && sfRenderWindow_isOpen(gm->wd)) {
		sfRenderWindow_drawRectangleShape(gm->wd,
					guis[actual_scene]->interface, NULL);
		sfRenderWindow_drawRectangleShape(gm->wd, pokemon->shape, NULL);
		for (int i = 0; i < 8; i++)
			sfRenderWindow_drawText(gm->wd, stats[i], NULL);
		sfRenderWindow_display(gm->wd);
		sfSleep(gm->tm);
		sfRenderWindow_clear(gm->wd, sfBlack);
		event(gm, guis);
	}
	for (int i = 0; i < 8; i++) {
		sfText_destroy(stats[i]);
	}
}

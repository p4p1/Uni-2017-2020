/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** display pokemon
*/

#include "my_rpg.h"

static int set_pkm_sfintrect(sfIntRect *pkm, int i, int ID_pkm)
{
	pkm->height = 240;
	pkm->width = 240;
	pkm->left = 0;
	if (ID_pkm <= 25 && ID_pkm > 0) {
		pkm->top = 0;
	} else if (ID_pkm > 25 && ID_pkm <= 50) {
		pkm->top = 240;
		i = i - 25;
	} else if (ID_pkm > 50 && ID_pkm <= 75) {
		pkm->top = 480;
		i = i - 50;
	} else if (ID_pkm > 100 && ID_pkm <= 125) {
		pkm->top = 720;
		i = i - 100;
	}
	return (i);
}

sfSprite *get_pkm_sprite(int ID_pkm, char* file)
{
	int i = ID_pkm;
	sfIntRect *pkm = malloc(sizeof(int) * 4);
	sfTexture *pkm_texture;
	sfSprite *pkm_sprite = sfSprite_create();

	i = set_pkm_sfintrect(pkm, i, ID_pkm);
	if (ID_pkm > 75 && ID_pkm <= 100) {
		pkm->top = 960;
		i = i - 75;
	} else if (ID_pkm > 125 && ID_pkm <= 150) {
		pkm->top = 1200;
		i = i - 125;
	}
	while (i != 1) {
		pkm->left = pkm->left + 240;
		i--;
	}
	pkm_texture = sfTexture_createFromFile(file, pkm);
	sfSprite_setTexture(pkm_sprite, pkm_texture, sfTrue);
	free(pkm);
	return (pkm_sprite);
}

void display_pokemons(sfRenderWindow *window, sfSprite *ally, sfSprite *enemy)
{
	sfRenderWindow_drawSprite(window, enemy, NULL);
	sfRenderWindow_drawSprite(window, ally, NULL);
}

void display_txt_fight(sfRenderWindow *window, sfText *txt)
{
	sfRenderWindow_drawText(window, txt, NULL);
}

sfText *create_txt_fight(sfVector2f pos, char *name, int char_size)
{
	sfFont *font = sfFont_createFromFile("res/font/Text_fint.ttf");
	sfText *new = sfText_create();

	sfText_setString(new, name);
	sfText_setFont(new, font);
	sfText_setCharacterSize(new, char_size);
	sfText_setPosition(new, pos);
	sfText_setColor(new, sfBlack);
	return (new);
}

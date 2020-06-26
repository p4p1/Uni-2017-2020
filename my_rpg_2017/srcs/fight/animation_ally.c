/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** display player throwing pokeball
*/

#include <time.h>
#include "my_rpg.h"

void wait_for(float a)
{
	clock_t t_c = clock();
	clock_t t_s = clock();

	while (((float)t_s/CLOCKS_PER_SEC) - ((float)t_c/CLOCKS_PER_SEC) < a)
		t_s = clock();
}

static void set_animation_options(sfIntRect *paralax, int a, sfVector2f *vector)
{
	if (a == 2) {
		paralax->left = 194;
		paralax->width = 226;
	}
	else if (a == 4) {
		paralax->left = 420;
		paralax->width = 250;
	}
	else if (a == 5) {
		paralax->left = 670;
		paralax->width = 260;
	}
	else if (a == 6) {
		paralax->width = 230;
		paralax->left = 930;
	}
	vector->x = vector->x - (a * 30);
}

static void set_sprite_texture(sfVector2f vector, sfTexture *text_p,
				sfSprite *sprite_player, sfIntRect *par)
{
	text_p = sfTexture_createFromFile("res/texture/dreseur_ally.png", par);
	sfSprite_setTexture(sprite_player, text_p, sfTrue);
	sfSprite_setPosition(sprite_player, vector);
}

static void set_paralax_base(sfIntRect *paralax)
{
	paralax->top = 0;
	paralax->left = 0;
	paralax->width = 194;
	paralax->height = 231;
}

int display_player_throwing_pokeball(sfRenderWindow *window, int a)
{
	sfIntRect *paralax = malloc(sizeof(int) * 4);
	sfVector2f vector = {100, 291};
	sfSprite *sprite_player = sfSprite_create();
	sfTexture *texture_player;

	set_paralax_base(paralax);
	set_animation_options(paralax, a, &vector);
	set_sprite_texture(vector, texture_player, sprite_player, paralax);
	sfRenderWindow_drawSprite(window, sprite_player, NULL);
	pokeball_turning(window, a);
	wait_for(0.2);
	if (a == 14)
		particles_pokeball(window);
	free(paralax);
}

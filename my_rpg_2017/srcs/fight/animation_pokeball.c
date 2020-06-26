/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** pokeball turning
*/

#include "my_rpg.h"

static void set_sprite_texture2(sfVector2f vector, sfTexture *tex_pk,
				sfSprite *sprite_pk, sfIntRect *par)
{
	tex_pk = sfTexture_createFromFile("res/texture/pokeball_throw.png",
	 par);
	sfSprite_setTexture(sprite_pk, tex_pk, sfTrue);
	sfSprite_setPosition(sprite_pk, vector);
}

static void set_paralax(sfIntRect *paralax_pkm, int a)
{
	a = a - 4;
	paralax_pkm->top = a * 75;
	paralax_pkm->left = 0;
	paralax_pkm->width = 72;
	paralax_pkm->height = 75;
}

static sfVector2f set_pokeball_pos(int a)
{
	sfVector2f vec = {100, 380};

	if (a <= 4)
		vec.y = vec.y - (25 * a);
	else
		vec.y = 255 + (20 * (a - 5));
	vec.x = vec.x + a * 3;
	return (vec);
}

void pokeball_turning(sfRenderWindow *window, int a)
{
	sfVector2f vector_pk = set_pokeball_pos(a);
	sfSprite *spri_pkb = sfSprite_create();
	sfTexture *text_pkb;
	sfIntRect *par_pkb = malloc(sizeof(int) * 4);

	if (a > 4) {
		set_paralax(par_pkb, a);
		set_sprite_texture2(vector_pk, text_pkb, spri_pkb, par_pkb);
		sfRenderWindow_drawSprite(window, spri_pkb, NULL);
	}
	free(par_pkb);
}

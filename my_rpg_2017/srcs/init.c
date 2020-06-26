/*
** EPITECH PROJECT, 2017
** init.c
** File description:
** <..>
*/

#include "../include/my_rpg.h"

static void store_txt(game_t *gm, sfVector2f pos, int j, int i)
{
	int index = 0;

	if (j == gm->shop_inventory->items[i]->type) {
		for (index = 0; gm->stuff[j]->items[index]->name != NULL
			; index++);
		gm->stuff[j]->items[index]->sfname = create_txt(pos,
					gm->shop_inventory->items[i]->name, 32);
		gm->stuff[j]->items[index]->name =
			my_strdup(gm->shop_inventory->items[i]->name);
	}
}

static void set_pos(game_t *gm, int j, sfVector2f pos)
{
	pos.y = 40.0;
	pos.x -= 20.0;
	sfRectangleShape_setPosition(gm->stuff[j]->selector->shape,
		pos);
	pos.y = 0.0;
	pos.x = 1400.0;
}

static void init_text(game_t *gm)
{
	int i = 0;
	int index = 0;
	sfVector2f pos = {1400.0, 0.0};

	for (int j = 0; j < 8; j++) {
		for (i = 0; i < 12; i++) {
			store_txt(gm, pos, j, i);
		}
		pos.y = 50.0;
		for (index = 0; gm->stuff[j]->items[index]->name != NULL
			; index++);
		gm->stuff[j]->items[index]->name = my_strdup("Fermer");
		gm->stuff[j]->items[index]->sfname = create_txt(pos, "Fermer",
		 32);
		gm->stuff[j]->items[index]->stock = 1;
		gm->stuff[j]->selector->idx = index;
		set_pos(gm, j, pos);
	}
}

game_t *init_struct(game_t *gm, sfTexture *texture)
{
	sfIntRect rect = {600, 2190, 40, 40};
	sfVector2f gap = {38.0, 0.0};
	sfVector2f base_pos = {990.0, 345.0};
	sfRectangleShape *shape = sfRectangleShape_create();
	int random = rand() % 3;

	sfRectangleShape_setTexture(shape, texture, sfFalse);
	sfRectangleShape_setTextureRect(shape, rect);
	gm->pocket_selector = create_selector(shape, &base_pos, gap);
	gm->menu = create_menu();
	gm->hero = malloc(sizeof(character_t));
	if (gm->hero == NULL)
		return (NULL);
	set_pokemons(gm);
	gm->hero->pokemon[0] = gm->pokemons[random];
	gm->shop_inventory = create_shop();
	config_shop(gm);
	for (int i = 0; i < 8; i++)
		gm->stuff[i] = create_inventory(texture);
	return (gm);
}

game_t *init(void)
{
	game_t *gm = malloc(sizeof(*gm));
	int		x = 0;
	int		y = 0;

	if (gm == NULL)
		return (NULL);
	gm->video_mode.width = WIDTH;
	gm->video_mode.height = HEIGHT;
	gm->video_mode.bitsPerPixel = 32;
	gm->wd = sfRenderWindow_create(gm->video_mode, NAME,
			sfDefaultStyle | sfFullscreen, NULL);
	gm = init_struct(gm,
	sfTexture_createFromFile("./res/texture/Interface_spritesheet.png",
				NULL));
	init_text(gm);
	gm->tm = sfMilliseconds(50);
	if ((gm->map = get_map("res/maps/basic.map", &x, &y)) == NULL)
		return (NULL);
	gm->new_obj =  create_hero_animation(gm->hero, x, y);
	gm->multiple_guis = config_multiple_gui();
	return (gm);
}

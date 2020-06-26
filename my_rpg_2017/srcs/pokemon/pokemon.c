/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** pokemon status and description
*/

#include "libconfig.h"
#include "my_rpg.h"

static sfRectangleShape *create_shape(config_setting_t *setting,
	sfTexture *texture)
{
	sfIntRect rect = rect_from_conf(config_setting_lookup(setting,
							"texture_rect"));
	sfVector2f size = {(float)rect.width, (float)rect.height};
	sfVector2f pos = {350.0, 500.0};
	sfRectangleShape *shape = sfRectangleShape_create();

	sfRectangleShape_setTexture(shape, texture, sfFalse);
	sfRectangleShape_setTextureRect(shape, rect);
	sfRectangleShape_setSize(shape, size);
	sfRectangleShape_setPosition(shape, pos);
	return (shape);
}

static pokemon_t *set_next_pokemon(config_setting_t *setting)
{
	pokemon_t *pokemon = malloc(sizeof(*pokemon));
	sfIntRect rect = rect_from_conf(config_setting_lookup(setting,
							"texture_rect"));
	const char *name;

	if (pokemon == NULL)
		return (NULL);
	pokemon->lvl = 5;
	config_setting_lookup_string(setting, "name", &name);
	pokemon->name = my_strdup(name);
	config_setting_lookup_int(setting, "ID", &pokemon->id);
	config_setting_lookup_int(setting, "HP", &pokemon->hp[1]);
	pokemon->hp[0] = pokemon->hp[1];
	config_setting_lookup_int(setting, "Attaque", &pokemon->attack);
	config_setting_lookup_int(setting, "Defense", &pokemon->defense);
	config_setting_lookup_int(setting, "Attaque_spe", &pokemon->att_spe);
	config_setting_lookup_int(setting, "Defense_spe", &pokemon->def_spe);
	config_setting_lookup_int(setting, "Vitesse", &pokemon->speed);
	pokemon->xp = 0;
	return (pokemon);
}

static void set_values(game_t *gm, config_setting_t *setting,
	sfTexture *texture)
{
	int count = config_setting_length(setting);

	gm->pokemons = malloc(sizeof(gm->pokemons) * (count + 1));
	if (gm->pokemons == NULL)
		return;
	for (int i = 0; i < count; i++) {
		gm->pokemons[i] =
		set_next_pokemon(config_setting_get_elem(setting, i));
		if (gm->pokemons[i] == NULL)
			return;
		gm->pokemons[i]->shape =
		create_shape(config_setting_get_elem(setting, i), texture);
	}
}

void set_pokemons(game_t *gm)
{
	config_t cfg;
	config_setting_t *setting;
	const char *texture_path;
	sfTexture *texture;

	config_init(&cfg);
	if (!config_read_file(&cfg, "./config/pokemon.cfg")) {
		my_printf("%s:%d- %s\n", config_error_file(&cfg),
			config_error_line(&cfg), config_error_text(&cfg));
	}
	config_lookup_string(&cfg, "POKEMON.Texture_file", &texture_path);
	texture = sfTexture_createFromFile(texture_path, NULL);
	setting = config_lookup(&cfg, "POKEMON.desc");
	set_values(gm, setting, texture);
	config_clear(&cfg);
}

/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** create all the structures needed for the fight
*/

#include "my_rpg.h"

static int my_nbrlen(long long int nbr)
{
	int i = 0;

	if (nbr == 0)
		return (1);
	while (nbr != 0) {
		nbr = nbr / 10;
		++i;
	}
	return (i);
}

static char *int_to_str(int to_change)
{
	int len = my_nbrlen(to_change);
	char *str = malloc(sizeof(char) * (len + 1));

	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	for (int i = 1; i <= len; i++) {
		str[len - i] = (to_change % 10) + 48;
		to_change = to_change / 10;
	}
	for (; str[0] == '0'; str++);
	return (str);
}

void set_ally(sfRenderWindow *window, pokemon_t *ally, int ID_ally_pkm)
{
 	char file[32] = "res/texture/sprite_pokemon1.png";
	sfVector2f namepos1 = {575, 410};
	sfVector2f lvlpos1 = {880, 410};

	ally->sfsprite = get_pkm_sprite(ID_ally_pkm, file);
	ally->sfname = create_txt(namepos1, ally->name, 25);
	sfSprite_setPosition(ally->sfsprite, (sfVector2f){100, 370});
	ally->sflvl = create_txt(lvlpos1, int_to_str(ally->lvl), 25);
}

void set_ennemy(sfRenderWindow *window, pokemon_t *ennemy, int ID_enemy_pkm)
{
	char file[32] = "res/texture/sprite_pokemon1.png";
	sfVector2f namepos2 = {45, 25};
	sfVector2f lvlpos2 = {350, 35};

	ennemy->sfsprite = get_pkm_sprite(ID_enemy_pkm, file);
	sfSprite_setPosition(ennemy->sfsprite, (sfVector2f){600, 10});
	ennemy->sfname = create_txt_fight(namepos2, ennemy->name, 25);
	ennemy->sflvl = create_txt_fight(lvlpos2, int_to_str(ennemy->lvl), 25);
}

pokemon_t *create_pokemon(int id)
{
	pokemon_t *new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);
	new->id = id;
	new->name = my_strdup(names[id - 1]);
	if (new->name == NULL)
		return (NULL);
	new->lvl = 1;
	return (new);
}

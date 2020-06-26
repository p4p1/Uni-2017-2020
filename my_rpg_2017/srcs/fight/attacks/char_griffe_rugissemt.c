/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** charge griffe
*/

#include <math.h>
#include <stdlib.h>
#include "my_rpg.h"

float randf(float min, float max)
{
	float result = rand() / (float) RAND_MAX;

	result = min + result * (max - min);
	return (result);
}

int deal_physical_damage(int might, pokemon_t *attack,
	pokemon_t *defense, int critical)
{
	int damage = 0;
	float multiplier = 1;
	int critical = 1;

	if (randf(0, 100) <= 6.25)
		critical = 2;
	multiplier = randf(0.85, 1.0) * critical;
	damage = (((attack->stat->exp[1] * 0.4 + 2) * attack->stat->att * might)
		 / (defense->stat->def * 50) + 2) * multiplier;
	defense->stat->life[0] -= damage;
	return (damage);
}

int atq_charge(pokemon_t *attacker, pokemon_t *defenser)
{
	int damage = 0;
	int critical = 1;
	int return_value = NORMAL;

	if (randf(0, 100) <= 6.25)
		critical = 2;
	damage = deal_physical_damage(40, attacker, defenser, critical);
	if (critical == 2)
		return_value += CRITICAL;
	return (return_value);
}

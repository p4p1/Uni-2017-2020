/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** all about the shop and it's creation
*/

#include "my_rpg.h"

shop_t *create_shop(void)
{
	shop_t *shop_inventory = malloc(sizeof(shop_t));

	if (shop_inventory == NULL)
		return (NULL);
	for (int i = 0; i < 14; i++) {
		shop_inventory->items[i] = malloc(sizeof(item_t));
		if (shop_inventory->items[i] == NULL)
			return (NULL);
		shop_inventory->items[i]->name = NULL;
		shop_inventory->items[i]->price = 0;
		shop_inventory->items[i]->sfname = NULL;
	}
	return (shop_inventory);
}

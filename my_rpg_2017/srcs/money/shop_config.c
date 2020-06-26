/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** initalize the shop from config file
*/

#include "libconfig.h"
#include "my_rpg.h"

static void set_item(config_setting_t *setting, item_t *item)
{
	char const *name;
	int check_int;

	config_setting_lookup_string(setting, "name", &name);
	item->name = my_strdup(name);
	config_setting_lookup_int(setting, "price", &check_int);
	item->price = check_int;
	config_setting_lookup_int(setting, "tier", &check_int);
	item->tier = check_int;
	config_setting_lookup_int(setting, "type", &check_int);
	item->type = check_int;
	item->stock = -1;
}

static int config_item_shop(config_setting_t *setting, game_t *gm)
{
	int count;
	config_setting_t *next_item;

	count = config_setting_length(setting);
	for (int i = 0; i < count; i++) {
		next_item = config_setting_get_elem(setting, i);
		set_item(next_item, gm->shop_inventory->items[i]);
		if (gm->shop_inventory->items[i]->name == NULL)
			return (84);
	}
	return (0);
}

int config_shop(game_t *gm)
{
	config_t cfg;
	config_setting_t *setting;

	config_init(&cfg);
	if (!config_read_file(&cfg, "./config/shop.cfg")) {
		my_printf("%s:%d - %s\n", config_error_file(&cfg),
			config_error_line(&cfg), config_error_text(&cfg));
	}
	setting = config_lookup(&cfg, "SHOP.items");
	if (config_item_shop(setting, gm) == 84)
		return (84);
	config_destroy(&cfg);
	return (0);
}

/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** configure all the gui of the project
*/

#include "libconfig.h"
#include "my_rpg.h"

sfIntRect rect_from_conf(config_setting_t *setting)
{
	sfIntRect rect;

	rect.left = config_setting_get_int_elem(setting, 0);
	rect.top = config_setting_get_int_elem(setting, 1);
	rect.height = config_setting_get_int_elem(setting, 2);
	rect.width = config_setting_get_int_elem(setting, 3);
	return (rect);
}

sfRectangleShape *set_gui_shape(config_setting_t *setting, sfTexture *texture)
{
	config_setting_t *rect_array = config_setting_lookup(setting,
							"texture_rect");
	sfIntRect rect = rect_from_conf(rect_array);
	config_setting_t *pos_array = config_setting_lookup(setting,
							"position");
	sfRectangleShape *shape = sfRectangleShape_create();
	sfVector2f pos;

	sfRectangleShape_setTexture(shape, texture, sfFalse);
	sfRectangleShape_setTextureRect(shape, rect);
	pos.x = config_setting_get_float_elem(pos_array, 0);
	pos.y = config_setting_get_float_elem(pos_array, 1);
	sfRectangleShape_setPosition(shape, pos);
	pos_array = config_setting_lookup(setting, "size");
	pos.x = config_setting_get_int_elem(pos_array, 1);
	pos.y = config_setting_get_int_elem(pos_array, 0);
	sfRectangleShape_setSize(shape, pos);
	return (shape);
}

gui_t *set_value(gui_t *gui, config_setting_t *setting, sfTexture *texture)
{
	config_setting_t *buttons_conf =
		config_setting_lookup(setting, "buttons");
	button_t **button_array = get_buttons(buttons_conf, texture);
	const char *name;
	sfRectangleShape *shape = set_gui_shape(setting, texture);

	config_setting_lookup_string(setting, "name", &name);
	gui = create_gui(shape, button_array, (char *)name);
	return (gui);
}

gui_t **set_gui_value(config_setting_t *setting, sfTexture *texture)
{
	int count;
	gui_t **all_gui = NULL;
	config_setting_t *setting_gui;

	if (setting != NULL) {
		count = config_setting_length(setting);
		all_gui = malloc(sizeof(gui_t *) * (count + 1));
		if (all_gui == NULL)
			return (NULL);
		for (int i = 0; i < count; i++) {
			setting_gui = config_setting_get_elem(setting, i);
			all_gui[i] = set_value(all_gui[i], setting_gui,
					texture);
			if (all_gui[i] == NULL)
				return (NULL);
		}
		all_gui[count] = NULL;
	}
	return (all_gui);
}

gui_t **init_guis(void)
{
	config_t cfg;
	config_setting_t *setting;
	sfTexture *texture;
	const char *texture_path;
	gui_t **guis;

	config_init(&cfg);
	if (!config_read_file(&cfg, "./config/gui.cfg")) {
		my_printf("%s:%d - %s\n", config_error_file(&cfg),
			config_error_line(&cfg), config_error_text(&cfg));
		config_destroy(&cfg);
		return (NULL);
	}
	config_lookup_string(&cfg, "GUI.Texture_file", &texture_path);
	texture = sfTexture_createFromFile(texture_path, NULL);
	setting = config_lookup(&cfg, "GUI.GUI_DEF");
	guis = set_gui_value(setting, texture);
	config_destroy(&cfg);
	return (guis);
}

/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** configure interface with multiple sub gui
*/

#include "libconfig.h"
#include "my_rpg.h"

sfRectangleShape *get_shape_from_config(config_setting_t *setting,
	sfTexture *texture)
{
	sfIntRect rect = rect_from_conf(config_setting_lookup(setting,
		"texture_rect"));
	sfVector2f pos_size[2];
	config_setting_t *pos = config_setting_lookup(setting, "pos");
	config_setting_t *size = config_setting_lookup(setting, "size");
	sfRectangleShape *shape = sfRectangleShape_create();

	pos_size[0].x = config_setting_get_float_elem(pos, 0);
	pos_size[0].y = config_setting_get_float_elem(pos, 1);
	pos_size[1].x = config_setting_get_float_elem(size, 0);
	pos_size[1].y = config_setting_get_float_elem(size, 1);
	sfRectangleShape_setTexture(shape, texture, sfFalse);
	sfRectangleShape_setTextureRect(shape, rect);
	sfRectangleShape_setPosition(shape, pos_size[0]);
	sfRectangleShape_setSize(shape, pos_size[1]);
	return (shape);
}

multiple_gui_t *set_multiple_gui(config_setting_t *setting, sfTexture *texture)
{
	char const *name;
	config_setting_t *background;
	multiple_gui_t *multiple_gui = malloc(sizeof(*multiple_gui));

	config_setting_lookup_string(setting, "name", &name);
	multiple_gui->name = my_strdup(name);
	background = config_setting_lookup(setting, "background");
	multiple_gui->background = get_shape_from_config(background, texture);
	multiple_gui->sub_gui = set_gui_value(
		config_setting_lookup(setting, "sub_gui"), texture);
	return (multiple_gui);
}

multiple_gui_t **get_gui_value(config_setting_t *setting, sfTexture *texture)
{
	int count;
	config_setting_t *next_gui;
	multiple_gui_t **multiple_gui;

	count = config_setting_length(setting);
	multiple_gui = malloc(sizeof(*multiple_gui) * (count + 1));
	if (multiple_gui == NULL)
		return (NULL);
	for (int i = 0; i < count; i++) {
		next_gui = config_setting_get_elem(setting, i);
		multiple_gui[i] = set_multiple_gui(next_gui, texture);
	}
	multiple_gui[count] = NULL;
	return (multiple_gui);
}

multiple_gui_t **config_multiple_gui(void)
{
	config_t cfg;
	config_setting_t *setting;
	char const *texture_path;
	sfTexture *texture;
	multiple_gui_t **multiple_gui;

	config_init(&cfg);
	if (!config_read_file(&cfg, "./config/gui.cfg")) {
		my_printf("%s:%d - %s\n", config_error_file(&cfg),
			config_error_line(&cfg), config_error_text(&cfg));
		config_destroy(&cfg);
		return (NULL);
	}
	config_lookup_string(&cfg, "MULTI_GUI.Texture_file", &texture_path);
	texture = sfTexture_createFromFile(texture_path, NULL);
	setting = config_lookup(&cfg, "MULTI_GUI.GUI");
	multiple_gui = get_gui_value(setting, texture);
	config_destroy(&cfg);
	return (multiple_gui);
}

void destroy_multiple_gui(multiple_gui_t *gui)
{
	sfRectangleShape_destroy(gui->background);
	free(gui->name);
	for (int i = 0; gui->sub_gui[i] != NULL; i++) {
		destroy_gui(gui->sub_gui[i]);
	}
	free(gui);
}

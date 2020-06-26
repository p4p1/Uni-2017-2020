/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** configure buttons
*/

#include <stdlib.h>
#include "libconfig.h"
#include "interface.h"

void set_button_design(config_setting_t *setting, sfTexture *texture,
	button_t *button)
{
	config_setting_t *rect_array = config_setting_lookup(setting,
							"texture_rect");
	sfIntRect rect = rect_from_conf(rect_array);
	const char *name;
	int check_int = 0;

	config_setting_lookup_int(setting, "is_text", &check_int);
	button_set_texture_rect(button, texture, &rect);
	if (check_int == 1) {
		config_setting_lookup_string(setting, "name", &name);
		button_set_sftext(button, (char *)name, 40);
	} else
		button->text = NULL;
	config_setting_lookup_int(setting, "is_off", &check_int);
	if (check_int == 1)
		button->state = DESACTIVATED;
}

button_t *set_next_button(config_setting_t *setting, sfTexture *texture)
{
	config_setting_t *pos_data = config_setting_lookup(setting,
							"position");
	sfVector2f pos_size[2];
	int int_info;
	int gap;
	button_t *new_button;

	pos_size[0].x = config_setting_get_float_elem(pos_data, 0);
	pos_size[0].y = config_setting_get_float_elem(pos_data, 1);
	pos_data = config_setting_lookup(setting, "size");
	pos_size[1].x = config_setting_get_float_elem(pos_data, 0);
	pos_size[1].y = config_setting_get_float_elem(pos_data, 1);
	config_setting_lookup_int(setting, "gap", &gap);
	config_setting_lookup_int(setting, "callback", &int_info);
	new_button = button_create(&pos_size[0], &pos_size[1],
				callback_array[int_info], gap);
	if (new_button == NULL)
		return (NULL);
	set_button_design(setting, texture, new_button);
	return (new_button);
}

button_t **get_buttons(config_setting_t *setting, sfTexture *texture)
{
	int count;
	button_t **button_array = NULL;
	config_setting_t *button_setting;

	if (setting != NULL) {
		count = config_setting_length(setting);
		button_array = malloc(sizeof(button_t *) * (count + 1));
		if (button_array == NULL)
			return (NULL);
		for (int i = 0; i < count; i++) {
			button_setting = config_setting_get_elem(setting, i);
			button_array[i] = set_next_button(button_setting,
							texture);
		}
		button_array[count] = NULL;
	}
	return (button_array);
}

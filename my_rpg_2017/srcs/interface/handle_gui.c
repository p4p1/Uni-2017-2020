/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** handle the interfaces
*/

#include <stdlib.h>
#include "my_rpg.h"

void display_gui(gui_t *gui, sfRenderWindow *window)
{
	sfRenderWindow_drawRectangleShape(window, gui->interface, NULL);
	if (gui->selector != NULL)
		sfRenderWindow_drawRectangleShape(window, gui->selector->shape,
						NULL);
	if (gui->buttons == NULL)
		return;
	for (int i = 0; gui->buttons[i] != NULL; i++) {
		sfRenderWindow_drawRectangleShape(window,
						gui->buttons[i]->shape, NULL);
		if (gui->buttons[i]->text != NULL)
			sfRenderWindow_drawText(window,
						gui->buttons[i]->text, NULL);
	}
}

int gui_set_position(gui_t *gui, sfVector2f position)
{
	gui->position = position;
	sfRectangleShape_setPosition(gui->interface, position);
	return (0);
}

void destroy_gui(gui_t *gui)
{
	if (gui->buttons != NULL)
		for (int i = 0; gui->buttons[i] != NULL; i++) {
			destroy_button(gui->buttons[i]);
		}
	sfRectangleShape_destroy(gui->interface);
	free(gui->name);
	free(gui);
}

gui_t *create_gui(sfRectangleShape *interface, button_t **buttons, char *name)
{
	gui_t *new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);
	new->name = my_strdup(name);
	new->interface = interface;
	new->buttons = buttons;
	return (new);
}

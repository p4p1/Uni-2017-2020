/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** display the buttons
*/

#include "my_rpg.h"

void destroy_button(button_t *button)
{
	sfRectangleShape_destroy(button->shape);
	if (button->text != NULL)
		sfText_destroy(button->text);
	free(button);
}

void button_event(button_t **buttons, sfVector2i *mouse_pos)
{
	int old_state;

	for (int i = 0; buttons[i] != NULL; i++) {
		if (buttons[i]->state == DESACTIVATED)
			continue;
		old_state = buttons[i]->state;
		buttons[i]->state = is_clicked(&buttons[i]->rect, mouse_pos);
		if (old_state != buttons[i]->state)
			button_change_state(old_state, buttons[i]);
	}
}

void display_button(button_t *button, sfRenderWindow *window)
{
	if (button->state != DESACTIVATED) {
		sfRenderWindow_drawRectangleShape(window, button->shape, NULL);
		if (button->text != NULL)
			sfRenderWindow_drawText(window, button->text, NULL);
	}
}

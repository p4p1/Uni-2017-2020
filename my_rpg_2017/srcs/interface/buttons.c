/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** handle buttons
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

int is_clicked(sfIntRect *rect, sfVector2i *mouse_pos)
{
	static int is_clicked = 0;
	static int block = 0;
	sfBool is_in = sfIntRect_contains(rect, mouse_pos->x, mouse_pos->y);

	if (is_clicked == 1 && block == 1)
		is_clicked = 0;
	if (is_in == sfTrue && block == 0)
		if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
			is_clicked = 1;
			block = 1;
		}
	if (sfMouse_isButtonPressed(sfMouseLeft) == sfFalse) {
		block = 0;
		is_clicked = 0;
	}
	if (is_in == sfTrue && is_clicked == 1)
		return (2);
	if (is_in == sfTrue)
		return (1);
	return (-1);
}

void button_change_state(int old_state, button_t *button)
{
	sfIntRect new_rect = sfRectangleShape_getTextureRect(button->shape);

	if (old_state == IDLE && button->state == CLICKED)
		new_rect.top += (button->hover_gap * 2);
	if (old_state == IDLE && button->state == HOVER)
		new_rect.top += button->hover_gap * button->state;
	if (old_state == HOVER && button->state == CLICKED)
		new_rect.top += button->hover_gap;
	if (old_state == CLICKED && button->state == HOVER)
		new_rect.top -= button->hover_gap;
	if (old_state == CLICKED && button->state == IDLE)
		new_rect.top -= (button->hover_gap * 2);
	if (old_state == HOVER && button->state == IDLE)
		new_rect.top -= button->hover_gap;
	sfRectangleShape_setTextureRect(button->shape, new_rect);
}

void button_set_sftext(button_t *button, char *text, int char_size)
{
	sfVector2f pos;
	sfText *new;

	pos.x = button->rect.height / 2;
	pos.y = button->rect.width / 2;
	new = create_txt(pos, text, char_size);
	button->text = new;
}

int button_set_texture_rect(button_t *button, sfTexture *texture,
			sfIntRect *rect)
{
	button->shape =  sfRectangleShape_create();
	sfVector2f pos;
	sfVector2f size;

	if (button->shape == NULL) {
		return (84);
	}
	pos.y = button->rect.top;
	pos.x = button->rect.left;
	size.y = button->rect.height;
	size.x = button->rect.width;
	sfRectangleShape_setTexture(button->shape, texture, sfFalse);
	sfRectangleShape_setTextureRect(button->shape, *rect);
	sfRectangleShape_setSize(button->shape, size);
	sfRectangleShape_setPosition(button->shape, pos);
	return (0);
}

button_t *button_create(sfVector2f *pos, sfVector2f *size,
			callback_button callback, int hover_gap)
{
	button_t *new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);
	new->rect.height = size->x;
	new->rect.width = size->y;
	new->rect.left = pos->x;
	new->rect.top = pos->y;
	new->callback = callback;
	new->text = NULL;
	new->state = IDLE;
	new->hover_gap = hover_gap;
	return (new);
}

/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** handle the dialog display
*/

#include <stdlib.h>
#include "interface.h"

static int get_next_letter(dial_box_t *dial_box)
{
	char *new_txt = malloc(sizeof(char) * (dial_box->letter + 1));

	if (new_txt == NULL)
		return (84);
	for (int i = 0; i < dial_box->letter; i++) {
		new_txt[i] = dial_box->txt[i];
	}
	new_txt[dial_box->letter] = '\0';
	sfText_setString(dial_box->to_display, new_txt);
	dial_box->letter++;
	return (0);
}

int display_dial_box(dial_box_t *dial_box, sfRenderWindow *window)
{
	sfTime box_time = sfClock_getElapsedTime(dial_box->clock);
	int milli = sfTime_asMilliseconds(box_time);

	sfRenderWindow_drawRectangleShape(window, dial_box->shape, NULL);
	sfRenderWindow_drawText(window, dial_box->speaker, NULL);
	if (milli >= 400) {
		get_next_letter(dial_box);
		sfRenderWindow_drawText(window, dial_box->to_display, NULL);
		sfClock_restart(dial_box->clock);
		if (dial_box->txt[dial_box->letter] == '\0')
			return (1);
	}
	return (0);
}

void charge_all_text(dial_box_t *dial_box)
{
	int letter_max = my_strlen(dial_box->txt);

	dial_box->letter = letter_max;
}

void change_text(dial_box_t *dial_box, char *new_text)
{
	dial_box->txt = new_text;
	dial_box->letter = 1;
}

dial_box_t *create_dial_box(sfText *speaker, char *txt,
			sfRectangleShape *shape)
{
	dial_box_t *new = malloc(sizeof(*new));
	sfClock *clock = sfClock_create();

	if (new == NULL || clock == NULL)
		return (NULL);
	new->shape = shape;
	new->speaker = speaker;
	new->txt = txt;
	new->clock = clock;
	new->letter = 1;
	return (new);
}

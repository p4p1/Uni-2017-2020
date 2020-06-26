/*
** EPITECH PROJECT, 2018
** my rpg
** File description:
** get position of the usr click
*/

#include "my_rpg.h"

static int click_on_atq(sfEvent *event)
{
	if (event->mouseButton.x > 0 && event->mouseButton.x < 440 &&
	    event->mouseButton.y > 570 && event->mouseButton.y < 600)
		return (0);
}

static int click_on_run(sfEvent *event, sfRenderWindow *window)
{
	if (event->mouseButton.x > 1610 && event->mouseButton.x < 1778 &&
	    event->mouseButton.y > 500 && event->mouseButton.y < 800) {
		return (1);
	}
}

static int click_on_bag(sfEvent *event)
{
	if (event->mouseButton.x > 0 && event->mouseButton.x < 440 &&
	    event->mouseButton.y > 570 && event->mouseButton.y < 600)
		return (0);
}

static int click_on_pok(sfEvent *event)
{
	if (event->mouseButton.x > 0 && event->mouseButton.x < 440 &&
	    event->mouseButton.y > 570 && event->mouseButton.y < 600)
		return (0);
}

int get_user_click(sfRenderWindow *window, sfEvent *event)
{
	if (click_on_run(event, window) == 1)
		return (-1);
	return (1);
}

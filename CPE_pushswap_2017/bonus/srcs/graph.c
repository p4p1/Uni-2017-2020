/*
** EPITECH PROJECT, 2017
** graph.c
** File description:
** <..>
*/

#include "pushswap.h"

static int get_width(struct gear *list)
{
	static int	len = 0;

	if (len == 0) {
		while (list != NULL) {
			len++;
			list = list->next;
		}
	}
	return ((WIDTH / len));
}

static int get_height(int value, struct gear *list)
{
	static int	big = 0;

	if (big == 0) {
		while (list != NULL) {
			big = (big < list->value) ? list->value : big;
			list = list->next;
		}
	}
	return (((1 + (value * HEIGHT)) / big) + 1);
}

int init_grap(struct pushswap *ps)
{
	sfVideoMode	video_mode;
	sfVector2f	size;
	struct gear	*tmp;

	if (ps == NULL)
		return (-1);
	tmp = ps->la;
	video_mode.width = WIDTH;
	video_mode.height = HEIGHT;
	ps->win = sfRenderWindow_create(video_mode, "pushswap",
			sfDefaultStyle, NULL);
	ps->texture_la = sfTexture_createFromFile("res/image.png", NULL);
	ps->texture_lb = sfTexture_createFromFile("res/image2.png", NULL);
	if (ps->win == NULL || ps->texture_la == NULL)
		return (-1);
	while (tmp != NULL) {
		size.x = (float)get_width(ps->la) / 400;
		size.y = (float)get_height(tmp->value, ps->la) / 400;
		tmp->pos.x = get_width(ps->la);
		tmp->pos.y = HEIGHT - get_height(tmp->value, ps->la);
		tmp->sp_la = sfSprite_create();
		tmp->sp_lb = sfSprite_create();
		sfSprite_setTexture(tmp->sp_la, ps->texture_la, sfTrue);
		sfSprite_setTexture(tmp->sp_lb, ps->texture_lb, sfTrue);
		sfSprite_setScale(tmp->sp_la, size);
		sfSprite_setScale(tmp->sp_lb, size);
		tmp = tmp->next;
	}
	return (0);
}

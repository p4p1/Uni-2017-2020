/*
** EPITECH PROJECT, 2017
** pixel.c
** File description:
** <..>
*/

#include "pushswap.h"

static void disp_l(pushswap_t *ps, struct gear *tmp, int *no, int list)
{
	sfVector2f	position;

	while (tmp != NULL) {
		position.y = tmp->pos.y;
		position.x = tmp->pos.x * (*no);
		*no += 1;
		sfSprite_setPosition((list) ? tmp->sp_la : tmp->sp_lb,
				position);
		sfRenderWindow_drawSprite(ps->win,
				(list) ? tmp->sp_la : tmp->sp_lb, NULL);
		tmp = tmp->next;
	}
}

void disp_list(pushswap_t *ps)
{
	int		no = 0;
	sfTime		fps;

	fps.microseconds = 100000;
	sfRenderWindow_clear(ps->win, sfBlack);
	disp_l(ps, ps->la, &no, 1);
	disp_l(ps, ps->lb, &no, 0);
	sfRenderWindow_display(ps->win);
	sfSleep(fps);
}

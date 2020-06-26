/*
** EPITECH PROJECT, 2017
** menu.c
** File description:
** <..>
*/

#include "my_rpg.h"

static struct queue *init_menu(void)
{
	struct queue	*menu = NULL;

	menu = add_queue(menu, create_background(-30, 0));
	return (menu);
}

static int event_handler(game_t *gm)
{
	int	no = -1;

	while (sfRenderWindow_pollEvent(gm->wd, &gm->event)) {
		if (gm->event.type == sfEvtClosed ||
				gm->event.key.code == sfKeyEscape)
			sfRenderWindow_close(gm->wd);
		if (gm->event.key.code == sfKeySpace)
			return (1);
	}
	return (no);
}

static void draw_sprite(game_t *gm, struct queue *menu)
{
	struct queue		*tmp = menu;
	entity_t	*el = NULL;

	while (tmp) {
		el = tmp->token;
		el->draw(el, gm->wd);
		tmp = tmp->next;
	}
}

int menu(game_t *gm)
{
	int			no = -1;
	static struct queue	*menu = NULL;

	if (menu == NULL)
		menu = init_menu();
	while (sfRenderWindow_isOpen(gm->wd) && no < 0) {
		no = event_handler(gm);
		draw_sprite(gm, menu);
		sfRenderWindow_display(gm->wd);
		sfSleep(gm->tm);
		sfRenderWindow_clear(gm->wd, sfBlack);
	}
	return (no);
}

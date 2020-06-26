/*
** EPITECH PROJECT, 2017
** old.c
** File description:
** <..>
*/

#include "my_rpg.h"

struct __entity__	*qu[22][40];

static void display_queue(game_t *gm)
{
	for (int i = 0; i < 22; i++)
		for (int j = 0; j < 40; j++) {
			qu[i][j]->draw(qu[i][j], gm->wd);
		}
}

struct __entity__ *next(struct __entity__ *self, struct game *gm, int x, int y)
{
	int	x_pos = (int)gm->hero->pos_map.x - 20;
	int	y_pos = (int)gm->hero->pos_map.y - 11;
	int	no = 0;

	no = can_draw(gm->map->map[y_pos + y][x_pos + x]);
	if (no == GROUND) {
		gm->map->map[y_pos + y][x_pos + x].on_s = 1;
		self = create_surface(x * 47, y * 47, gm->map->map[y_pos + y]
				[x_pos + x].tile.type);
	} else if (no == COLIDABLE) {
		gm->map->map[y_pos + y][x_pos + x].on_s = 1;
		self = create_colidable(x * 47, y * 47, gm->map->map[y_pos + y]
				[x_pos + x].tile.type);
	}
	return (self);
}

static int set_pos(game_t *gm, int x_pos, int y_pos)
{
	if (x_pos < 0) {
		gm->hero->pos_map.x = 20;
		return (1);
	}
	if (y_pos < 0) {
		gm->hero->pos_map.y = 11;
		return (1);
	}
	if (x_pos > gm->map->head.width) {
		gm->hero->pos_map.x = gm->map->head.width - 1;
		return (1);
	}
	if (y_pos > gm->map->head.height) {
		gm->hero->pos_map.y = gm->map->head.height- 1;
		return (1);
	}
	return (0);
}

static void set_queue(game_t *gm, int x, int y)
{
	sfVector2f	pos = {100, 100};
	sfVector2f	size = {500, 100};
	sfTexture	*tex = sfTexture_createFromFile("res/texture/bar.png",
			NULL);
	sfIntRect	rect = {0, 0, 500, 100};
	bar_t		*bar = bar_create(&pos, &size, tex, &rect);

	for (int i = 0; i < 22; i++) {
		update_bar(bar, i, 22);
		for (int j = 0; j < 40; j++) {
			qu[i][j] = next(qu[i][j], gm, j, i);
		}
		my_printf("loading: %d.%d\n", i, 21);
		sfRenderWindow_clear(gm->wd, sfBlack);
		sfRenderWindow_drawRectangleShape(gm->wd, bar->shape, NULL);
		sfRenderWindow_display(gm->wd);
	}
}

void disp_map(game_t *gm)
{
	int	x_pos = (int)gm->hero->pos_map.x - 20;
	int	y_pos = (int)gm->hero->pos_map.y - 11;
	static int	first = 0;

	if (!first) {
		set_queue(gm, x_pos, y_pos);
		first = 1;
	}
	if (set_pos(gm, x_pos, y_pos))
		return;
	if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue)
		paralax_up(gm);
	if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
		paralax_down(gm);
	if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue)
		paralax_right(gm);
	if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
		paralax_left(gm);
	sfRenderWindow_clear(gm->wd, sfBlack);
	display_queue(gm);
	sfRenderWindow_drawRectangleShape(gm->wd, gm->hero->trainer, NULL);
	sfRenderWindow_display(gm->wd);
}

/*
** EPITECH PROJECT, 2017
** duck.c
** File description:
** <..>
*/

#include "my_hunter.h"

static int move_duck_fp(struct duck *duck, int x, int y)
{
	srand(time(NULL));
	if (duck->dead == 2) {
		duck->dead = 0;
		duck->pos.x = 0;
		duck->pos.y = (rand() % HEIGHT / 3) + 10;
	}
	duck->pos.x += x;
	duck->pos.y += y;
	if (duck->pos.y < HEIGHT && duck->dead == 1) {
		duck->dead = 2;
	}
	if (duck->pos.x > WIDTH) {
		duck->dead = 0;
		duck->pos.x = 0;
		duck->pos.y = (rand() % HEIGHT / 3) + 10;
		return (1);
	}
	return (0);
}

static int animate_duck_fp(struct duck *self, struct game *s_game, int frame)
{
	int	ret = 0;

	frame = (frame / 35) % 3;
	if (self->dead == 1) {
		ret = self->move(self, 0, 1);
		return (ret);
	}
	if (self->c == 'R')
		ret = self->move(self, 1, 0);
	else if (self->c == 'G')
		ret = self->move(self, 4, 0);
	else
		ret = self->move(self, 2, 0);
	sfSprite_setPosition(self->sprite[frame], self->pos);
	sfRenderWindow_drawSprite(s_game->window, self->sprite[frame], NULL);
	return (ret);
}

static int colision_duck_fp(struct duck *self, int x, int y)
{
	if (self->pos.x <= x && (self->pos.x + 110) >= x) {
		if (self->pos.y <= y && (self->pos.y + 110) >= y) {
			self->dead = 1;
			return (1);
		}
	}
	return (0);
}

static struct duck *set_functions(struct duck *dk)
{
	dk->dead = 0;
	dk->move = &move_duck_fp;
	dk->animate = &animate_duck_fp;
	dk->colision = &colision_duck_fp;
	return (dk);
}

struct duck *build_duck(char c)
{
	struct duck	*dk = (struct duck *)malloc(sizeof(struct duck));
	sfIntRect	*size = (sfIntRect *)malloc(sizeof(sfIntRect));
	int		i = 0;

	if (dk == 0 || size == 0)
		return (0);
	dk->pos.x = 0;
	dk->pos.y = (rand() % HEIGHT) + 10;
	dk->c = c;
	size->height = 110;
	size->width = 110;
	size->left = 0;
	size->top = 0;
	dk->sprite = malloc(sizeof(sfSprite *) * NUMBER_OF_DUCKS_FRAMES);
	for (i = 0; i < NUMBER_OF_DUCKS_FRAMES; i++) {
		dk->texture = sfTexture_createFromFile(get_duck_path(c), size);
		dk->sprite[i] = sfSprite_create();
		sfSprite_setTexture(dk->sprite[i], dk->texture, sfTrue);
		size->left += 110;
	}
	return (set_functions(dk));
}

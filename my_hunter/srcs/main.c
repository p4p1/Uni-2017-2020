/*
** EPITECH PROJECT, 2017
** window.c
** File description:
** <..>
*/

#include "my_hunter.h"

static int err(char *str)
{
	write(2, str, my_strlen(str));
	return (84);
}

static void draw_sprites(struct game *s_game, unsigned int frame)
{
	int	i = 0;

	sfRenderWindow_drawSprite(s_game->window, s_game->sp, NULL);
	for (i = 0; i < NUMBER_OF_DUCKS; i++) {
		if (s_game->ducks[i]->animate(s_game->ducks[i], s_game, frame))
			s_game->lost++;
	}
}

static int usage(int argc, char **argv)
{
	char	ch = 0;
	int	ret = 0;

	while ((ch = my_getopt(argc, argv, "hc:")) != -1) {
		if (ch == '?')
			return (err("[ERROR] Argument does not exist!\n"));
		if (ch == 'c')
			ret = (my_strlen(my_optarg) == 1)? my_optarg[0] : 0;
		if (ch == 'h') {
			my_printf("USAGE %s:\n"
			"\nTo play this game you have to kill as many ducks as"
			"possible. To kill a duck just click on it\n"
			"To set difficulty use the -cR/G/B flag\n"
			"Example %s -c R\n", argv[0], argv[0]);
			return (84);
		}
	}
	return (ret);
}

int main(int argc, char **argv)
{
	struct game	s_game;
	unsigned int	i = 1;
	char		dificulty = 0;

	if ((dificulty = usage(argc, argv)) == 84)
		return (84);
	if (init(&s_game, dificulty))
		return (err("[ERROR] Could not create window"));
	while (sfRenderWindow_isOpen(s_game.window) && s_game.lost < 3) {
		if (event_handler(&s_game) < 0)
			break;
		draw_sprites(&s_game, i);
		sfRenderWindow_display(s_game.window);
		sfSleep(s_game.fps);
		sfRenderWindow_clear(s_game.window, sfBlack);
		++i;
	}
	my_printf("score: %d\n", s_game.score);
	return (0);
}

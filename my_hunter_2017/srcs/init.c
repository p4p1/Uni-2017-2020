/*
** EPITECH PROJECT, 2017
** init.c
** File description:
** <..>
*/

#include "my_hunter.h"

char *get_duck_path(char ch)
{
	char	*red_duck = my_strdup("res/duck_red.png");
	char	*green_duck = my_strdup("res/duck_green.png");
	char	*blue_duck = my_strdup("res/duck_blue.png");

	if (ch == 'R')
		return (red_duck);
	if (ch == 'B')
		return (blue_duck);
	else
		return (green_duck);
	return (0);
}

int init(struct game *s_game, int difficulty)
{
	int	i = 0;

	s_game->fps.microseconds = FRAME_RATE;
	s_game->video_mode.width = WIDTH;
	s_game->video_mode.height = HEIGHT;
	s_game->video_mode.bitsPerPixel = 32;
	s_game->window = sfRenderWindow_create(s_game->video_mode, GAME_NAME,
			sfDefaultStyle, NULL);
	s_game->tx = sfTexture_createFromFile("res/background.png", NULL);
	s_game->sp = sfSprite_create();
	sfSprite_setTexture(s_game->sp, s_game->tx, sfTrue);
	s_game->ducks = (struct duck **)malloc(NUMBER_OF_DUCKS *
					sizeof(struct duck *));
	s_game->score = 0;
	s_game->lost = 0;
	for (i = 0; i < NUMBER_OF_DUCKS; i++) {
		s_game->ducks[i] = build_duck(difficulty);
	}
	return (0);
}

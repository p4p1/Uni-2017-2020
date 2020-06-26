/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** <..>
*/

#include "../include/my_rpg.h"

int actual_scene = 0;

static int check_display(char const *display)
{
	if (my_strcmp(display, ":0.0") == 0)
		return (0);
	return (84);
}

static int check_env(char **env)
{
	int i;

	if (env == NULL)
		return (84);
	for (i = 0; env[i] != NULL; i++) {
		if (my_strncmp(env[i], "DISPLAY=", 8) == 0)
			return (check_display(env[i] + 8));
	}
	if (i == 0)
		return (84);
	return (0);
}

int main(int ac, char **av, char **env)
{
	if (check_env(env) == 84)
		return (84);
	srand(time(NULL));
	game_t *gm = init();
	if (gm == NULL)
		return (84);
	sfRenderWindow_setFramerateLimit(gm->wd, 60);
	(void) ac;
	(void) av;
	gui_t **gui = init_guis();
	if (gui == NULL)
		return (84);
	while (menu(gm) == 1)
		game(gm, gui);
	destroy(gm, gui);
	return (0);
}

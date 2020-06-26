/*
** EPITECH PROJECT, 2017
** my_hunter.h
** File description:
** header file for my_hunter
*/

#ifndef MY_HUNTER_H_
#define MY_HUNTER_H_

#include "my.h"
#include "my_getopt.h"

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GAME_NAME "my_hunter"
#define FRAME_RATE 3000
#define NUMBER_OF_DUCKS 2
#define NUMBER_OF_DUCKS_FRAMES 3
#define WIDTH 1080
#define HEIGHT 720

struct game;

struct duck {
	sfTexture	*texture;
	sfSprite	**sprite;
	sfIntRect	*size;
	sfVector2f	pos;
	int		(*move)(struct duck *, int, int);
	int		(*animate)(struct duck *, struct game*, int);
	int		(*colision)(struct duck*, int, int);
	char		c;
	int		dead;
	unsigned int	status;
};

struct game {
	struct duck		**ducks;
	sfRenderWindow		*window;
	sfVideoMode		video_mode;
	sfTime			fps;
	sfTexture		*tx;
	sfSprite		*sp;
	int			score;
	int			lost;
};

int event_handler(struct game *);
int init(struct game *, int difficulty);
struct duck *build_duck(char c);
char *get_duck_path(char ch);
void destroy_all(struct game *);

#endif

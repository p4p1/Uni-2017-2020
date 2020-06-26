/*
** EPITECH PROJECT, 2017
** my_runner.h
** File description:
** header file my_runner
*/

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

#include "my.h"
#include "my_getopt.h"
#include "my_fgets.h"

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <time.h>

#define PLAYER_FRAMES 3
#define TILE_NUMBER 14
#define BACKGROUND_NO 6
#define GRAVITY 2.5f;
#define WIDTH 1080
#define HEIGHT 720

enum tile_type {
	TOP_PIPE = 1,
	BOTTOM_PIPE = 2
};

enum background_type {
	SKY = 1,
	GRASS = 2,
	MARIO = 3
};

typedef struct __entity__ player_t;
typedef struct __entity__ enemy_t;
typedef struct __entity__ background_t;
typedef struct __entity__ button_t;
typedef struct __entity__ tile_t;
typedef struct __entity__ title_t;

struct size_st
{
	int	width;
	int	height;
};

struct settings
{
	int	no_tile;
	int	no_mob;
	int	infin_mode;
};

struct __entity__
{
	struct size_st	size;
	sfVector2f	pos;
	sfSprite	**sprite;
	char		ch;
	int		frame;
	int		actual_frame;
	float		dy;
	int		(*move)(struct __entity__ *, int, int);
	int		(*animate)(struct __entity__ *, sfRenderWindow *);
};

struct game
{
	struct settings	*set;
	int		score;
	sfRenderWindow	*win;
	sfTime		fps;
	sfMusic		*music;
	sfSound		*sound;
	sfText		*score_text;
	sfSoundBuffer	*sound_buff;
	background_t	**bg;
	player_t	*p1;
	player_t	**mob;
	enemy_t		**en;
	tile_t		**ground;
	button_t	*btn_start;
	button_t	*btn_info;
	title_t		*title;
	title_t		*death_title;
};

struct game *init(char *, struct settings *st);
int menu(struct game *);
int death(struct game *);
int main_game(struct game *);
int animate_sprite_fp(struct __entity__ *, sfRenderWindow *);
int moving_sprite_fp(struct __entity__ *, int, int);
int colision(struct __entity__ *, struct __entity__ *);
int counter(char *);
int info(struct game *);
int mob_counter(char *);
int create_map(struct game *, char *);
int create_elem(char *, struct game *);
player_t *create_player(int, int);
tile_t *create_tile(int, int, int);
background_t *create_background(int, int, int);
button_t *create_button(int, int);
title_t *create_title(int, int);
title_t *create_death_title(int, int);
button_t *create_info_button(int, int);
player_t *create_mob(int, int);

#endif

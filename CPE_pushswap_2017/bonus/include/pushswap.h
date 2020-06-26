/*
** EPITECH PROJECT, 2017
** pushswap.h
** File description:
** the pushswap header file
*/

#ifndef PUSHSWAP_H_
#define PUSHSWAP_H_

#include "my.h"
#include "my_getopt.h"

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 1080
#define HEIGHT 720

typedef struct pushswap	pushswap_t;

struct gear {
	int			value;
	sfVector2f		pos;
	sfSprite		*sp_la;
	sfSprite		*sp_lb;
	struct gear		*next;
	struct gear		*back;
};

struct pushswap {
	struct gear	*la;
	struct gear	*lb;
	char		*buffer;
	int		pos;
	int		buf_siz;
	unsigned int	verbose;
	sfRenderWindow	*win;
	sfTexture	*texture_la;
	sfTexture	*texture_lb;
};

struct pushswap *init_pushswap(int *, char **);
int init_grap(struct pushswap *);
int pa(pushswap_t *);
int pb(pushswap_t *);
void put_in_b(pushswap_t *);
void add_str(char const *, pushswap_t *);
int rra(pushswap_t *);
void reverse_list(pushswap_t *);
int ra(pushswap_t *);
int get_last(struct gear *);
void disp_list(pushswap_t *);
int is_sorted(struct gear *);

#endif

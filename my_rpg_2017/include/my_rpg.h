/*
** EPITECH PROJECT, 2017
** my_rpg.h
** File description:
** <..>
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include "fight.h"
#include "my.h"
#include "clist.h"
#include "size.h"
#include "interface.h"

#define WIDTH 1920
#define HEIGHT 1080
#define NAME "epimon"

extern int actual_scene;

enum attack_type {
	CHARGE
};

enum item_type {
	OBJECT,
	MEDICINE,
	POKEBALL,
	CT_CS,
	BERRIES,
	MAIL,
	BATTLE_OBJECT,
	KEY_OBJECT,
};

enum entity_type {
	TREE1=0,
	TREE2=1,
	TREE3=2,
	TREE4=3,
	TREESNOW1=4,
	TREESNOW2=5,
	GRASS1=6,
	DIRT1=7,
	DIRT2=8,
	DIRT3=9,
	POKECENTER=10,
	POKEMARKET=11,
	PLAYER=12,
	NPC=13,
	MISC=14
};

enum ground_type {
	COLIDABLE,
	GROUND
};

typedef struct header header_t;
struct header {
	int		magic;
	char		name[20];
	unsigned int	size;
	unsigned int	width;
	unsigned int	height;
} __attribute__((packed));

typedef struct tile tile_t;
struct tile {
	int		x;
	int		y;
	int		type;
} __attribute__((packed));

typedef struct map map_t;
struct map {
	struct tile	tile;
	int		on_s;
};

typedef struct map_info map_info_t;
struct map_info {
	struct header	head;
	struct map	**map;
	int		px;
	int		py;
};

typedef struct __entity__ entity_t;
struct __entity__ {
	sfSprite		**sprite;
	int			(*draw)(struct __entity__ *, sfRenderWindow *);
	int			(*move)(struct __entity__ *, int, int);
	int			(*collide)(struct __entity__ *, int, int);
	sfVector2f		pos;
	enum entity_type	type;
};

typedef struct s_stats stats_t;

typedef struct attack	attack_t;
typedef struct pokemon	pokemon_t;
struct pokemon {
	int		id;
	sfRectangleShape *shape;
	char *name;
	sfSprite *sfsprite;
	sfText *sfname;
	sfText *sflvl;
	int	lvl;
	int	hp[2];
	int attack;
	int defense;
	int att_spe;
	int def_spe;
	int speed;
	int xp;
	attack_t	*attacks[4];
};


struct attack {
	enum attack_type	type;
	int			(*attack)(pokemon_t *, pokemon_t *);
};

typedef struct character character_t;
struct character
{
	sfRectangleShape	*trainer;
	int			speed;
	sfVector2f		size;
	int pokedollards;
	sfVector2f		pos;
	sfVector2f		pos_map;
	sfClock *clock;
	pokemon_t *pokemon[6];
};

typedef struct s_object
{
	enum entity_type type;
	sfTexture *texture;
	sfIntRect actual_state;
	int gap;
	int nb_anim[2];
	sfClock *clock;
} object_t;

typedef void (*item_callback)(item_t *, game_t *);
typedef struct item item_t;
struct item
{
	char *name;
	char type;
	int tier;
	int stock;
	int price;
	sfText *sfname;
	item_callback callback;
};

typedef struct inventory inventory_t;
struct inventory
{
	item_t *items[13];
	int status;
	item_selector_t *selector;
};

typedef struct shop shop_t;
struct shop
{
	item_t *items[14];
	int status;
};

typedef struct game game_t;
struct game {
	sfRenderWindow		*wd;
	sfVideoMode		video_mode;
	sfTime			tm;
	sfEvent			event;
	sfRectangleShape	*menu;
	struct map_info		*map;
	character_t		*hero;
	shop_t *shop_inventory;
	object_t		*new_obj;
	inventory_t		*stuff[8];
	pocket_selector_t *pocket_selector;
	multiple_gui_t **multiple_guis;
	pokemon_t **pokemons;
};

game_t *init(void);
int menu(game_t *gm);
int game(game_t *gm, gui_t **gui);
void destroy(game_t *, gui_t **guis);
int detecte_press(sfKeyCode keyboard, game_t *gm);

// check type
int can_draw(struct map self);

// Map parser
struct map_info *get_map(char *, int *, int *);
struct map **alloc_map(struct header head);

// test
int test(game_t *gm);

// create
sfIntRect *get_size(enum entity_type type);
struct __entity__ *create_colidable(int x, int y, enum entity_type type);
struct __entity__ *create_surface(int x, int y, enum entity_type type);
struct __entity__ *create_background(int x, int y);
entity_t *create_map(int x, int y);
void destroy_entity(struct __entity__ *self);
sfText *create_txt(sfVector2f pos, char *txt, int char_size);
sfRectangleShape *create_menu(void);
int config_shop(game_t *gm);
void set_pokemons(game_t *gm);
sfText *create_txt_fight(sfVector2f pos, char *name, int char_size);


// display
void disp_map(game_t *);
void paralax_up(game_t *gm);
void paralax_down(game_t *gm);
void paralax_left(game_t *gm);
void paralax_right(game_t *gm);
void move_tab_up(void);
struct __entity__ *next(struct __entity__ *self, struct game *gm, int x, int y);

object_t *create_hero_animation(character_t *hero, int x, int y);
void player_movement(character_t *hero, game_t *gm, object_t *new_object);
int animate(object_t *new_object, character_t *hero);
void create_character(character_t *hero, object_t *obj, int x, int y);
void display_menu(gui_t **guis, game_t *gm);
void stat_menu(gui_t **guis, game_t *gm, pokemon_t *pokemon);

// movement
void down_movement(character_t *hero, object_t *new_object);
void up_movement(character_t *hero, object_t *new_object);
void left_movement(character_t *hero, object_t *new_object);
void right_movement(character_t *hero, object_t *new_object);
void speed_variation(character_t *hero, game_t *gm);

//inventory
void open_menu(game_t *gm, inventory_t *stuff);
void fill_inventory(game_t *gm, item_t *items);
inventory_t *create_inventory(sfTexture *texture);
void display_inventory(game_t *gm);

//shop
shop_t *create_shop(void);
void using_shop(game_t *gm);
void fill_shop(game_t *gm);

//random
int find_savage_pokemon(void);

//selector
item_selector_t *create_item_selector(sfRectangleShape *shape);
void select_event(pocket_selector_t *selector, game_t *gm);
void item_selector_event(inventory_t *pocket, game_t *gm);

//start fight
int start_fight(gui_t **guis, game_t *gm);

//a virer avant rendu (fonction pour test)
void set_ally(sfRenderWindow *window, pokemon_t *ally, int id);
void set_ennemy(sfRenderWindow *window, pokemon_t *ennemy, int id);

#endif

/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** GUI_
*/

#ifndef GUI_
#define GUI_

#include "../extern_libs/libconfig.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>

typedef struct item item_t;
typedef struct game game_t;
typedef struct s_dial_box dial_box_t;
typedef struct s_button button_t;
typedef struct s_gui gui_t;
typedef struct s_bar bar_t;
typedef struct s_item_selector item_selector_t;
typedef struct s_pocket_selector pocket_selector_t;
typedef struct s_multiple_gui multiple_gui_t;
typedef void (*callback_button)(button_t *, game_t *);

void fuite_button(button_t *button, game_t *gm);
void attack_button(button_t *button, game_t *gm);
void annuler_button(button_t *button, game_t *gm);
void play(button_t *, game_t *);
void quit(button_t *, game_t *);
void resume(button_t *, game_t *);
void attack(button_t *, game_t *);
void quit_to_start(button_t *, game_t *);
void pokemon_button(button_t *, game_t *);
void bag_button(button_t *, game_t *);
void save_button(button_t *, game_t *);
void option_button(button_t *, game_t *);
void button_stat_pokemon(button_t *, game_t *);
int is_clicked(sfIntRect *rect, sfVector2i *mouse_pos);
void button_change_state(int, button_t *button);
sfIntRect rect_from_conf(config_setting_t *setting);
int button_set_texture_rect(button_t *button, sfTexture *texture,
			sfIntRect *rect);
button_t *button_create(sfVector2f *pos, sfVector2f *size,
			callback_button callback, int hover_gap);
void button_set_sftext(button_t *button, char *text, int char_size);
button_t **get_buttons(config_setting_t *setting, sfTexture *texture);
gui_t *create_gui(sfRectangleShape *interface, button_t **buttons, char *name);
gui_t **init_guis(void);
void button_event(button_t **, sfVector2i*);
void display_button(button_t *, sfRenderWindow *);
pocket_selector_t *create_selector(sfRectangleShape *, sfVector2f *base_pos,
			sfVector2f gap);
gui_t **set_gui_value(config_setting_t *, sfTexture *);
multiple_gui_t **config_multiple_gui(void);
sfRectangleShape *get_shape_from_config(config_setting_t *setting, sfTexture *texture);
void update_bar(bar_t *bar, float new_value, float max_value);
bar_t *bar_create(sfVector2f *pos, sfVector2f *size, sfTexture *texture, sfIntRect *rect);
void destroy_item_selector(item_selector_t *);
void destroy_gui(gui_t *);
void destroy_multiple_gui(multiple_gui_t *);
void destroy_selector(pocket_selector_t *);
void destroy_button(button_t *);

enum e_button_state
{
	IDLE = -1,
	HOVER = 1,
	CLICKED = 2,
	DESACTIVATED = 3
};


static const callback_button callback_array[] = {play,
						quit,
						attack,
						quit_to_start,
						pokemon_button,
						bag_button,
						save_button,
						option_button,
						button_stat_pokemon,
						attack_button,
						annuler_button,
						fuite_button};


struct s_bar
{
	sfIntRect rect;
	sfRectangleShape *shape;
	float percentage;
	sfClock *clock;
	sfVector2f *size;
};

struct s_button
{
	sfIntRect rect;
	int state;
	callback_button callback;
	sfRectangleShape *shape;
	int hover_gap;
	sfText *text;
};

struct s_pocket_selector
{
	sfRectangleShape *shape;
	sfVector2f *base_pos;
	sfVector2f gap;
	int idx;
};

struct s_item_selector
{
	sfRectangleShape *shape;
	int idx;
};

struct s_dial_box
{
	char *txt;
	sfText *to_display;
	sfText *speaker;
	sfRectangleShape *shape;
	sfClock *clock;
	int letter;
};

struct s_multiple_gui
{
	char *name;
	sfRectangleShape *background;
	gui_t **sub_gui;
};

struct s_gui
{
	char *name;
	sfVector2f position;
	sfRectangleShape *interface;
	button_t **buttons;
	item_selector_t *selector;
};

#endif /* GUI_ */

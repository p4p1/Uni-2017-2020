/*
** EPITECH PROJECT, 2017
** debug.c
** File description:
** <..>
*/

#include "tetris.h"

static char *set_unprintable_chars(char *str)
{
	char	*tmp = malloc(sizeof(char) * my_strlen(str) * 2);
	int	i = 0;
	int	j = 0;

	if (tmp == NULL)
		return (NULL);
	for (i = 0, j = 0; str[i] && j < my_strlen(str) * 2; i++, j++) {
		if (str[i] == 27) {
			tmp[j] = '^';
			tmp[j + 1] = 'E';
			++j;
		} else {
			tmp[j] = str[i];
		}
	}
	tmp[j] = '\0';
	return (tmp);
}

static char *get_key_char(int key)
{
	char	*str = NULL;

	if (key == KEY_LEFT)
		return (set_unprintable_chars(tigetstr("kcub1")));
	if (key == KEY_RIGHT)
		return (set_unprintable_chars(tigetstr("kcuf1")));
	if (key == KEY_UP)
		return (set_unprintable_chars(tigetstr("kcuu1")));
	if (key == KEY_DOWN)
		return(set_unprintable_chars(tigetstr("kcud1")));
	if (key == ' ')
		return (my_strdup("(space)"));
	str = malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	str[0] = key;
	str[1] = '\0';
	return (str);
}

static void display_tetrimino(struct queue *el)
{
	struct shapes	*shape = (el) ? el->token : NULL;

	my_printf("Tetriminos : %d\n", (shape) ? shape->no : 0);
	while (el) {
		shape = el->token;
		if (shape->error_flag) {
			my_printf("Tetriminos : Name %s : Error\n",
					shape->name);
			el = el->next;
			continue;
		}
		my_printf("Tetriminos : Name %s : Size %d*%d : Color %d :\n",
			shape->name, shape->width, shape->height, shape->color);
		for (int i = 0; i < (int)shape->height && shape->shape[i];
				i++) {
			my_printf("%s\n", shape->shape[i]);
		}
		el = el->next;
	}
}

void debug_mode(struct args *arg, struct queue *shapes)
{
	if (arg == NULL)
		return;
	my_printf("*** DEBUG MODE ***\n");
	my_printf("Key Left : %s\n", get_key_char(arg->key_left_b));
	my_printf("Key Right : %s\n", get_key_char(arg->key_right_b));
	my_printf("Key Turn : %s\n", get_key_char(arg->key_turn_b));
	my_printf("Key Drop : %s\n", get_key_char(arg->key_drop_b));
	my_printf("Key Quit : %s\n", get_key_char(arg->key_quit_b));
	my_printf("Key Pause : %s\n", get_key_char(arg->key_pause_b));
	my_printf("Next : %s\n", (arg->without_next_flag) ? "No" : "Yes");
	my_printf("Level : %d\n", arg->level);
	my_printf("Size : %d*%d\n", arg->map_size[0], arg->map_size[1]);
	display_tetrimino(shapes);
	my_printf("Press any key to start Tetris\n");
}

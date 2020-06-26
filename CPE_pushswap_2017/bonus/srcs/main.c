/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main file for the pushswap
*/

#include "pushswap.h"

static void shift_algo(pushswap_t *self, int len)
{
	int	j = 0;
	int	mask = 1;
	static int	move = 0;

	while (j <= len) {
		if (((self->la->value >> move) & mask)
				== 0) {
			pb(self);
		} else {
			ra(self);
		}
		j++;
	}
	move++;
	put_in_b(self);
}

static void main_algo(pushswap_t *ps, int len)
{
	int	j = 0;

	while (j <= 31) {
		shift_algo(ps, len);
		j++;
	}
	reverse_list(ps);
	ps->buffer[ps->pos] = '\n';
	ps->buffer[ps->pos + 1] = '\0';
}

static void end(pushswap_t *ps)
{
	sfEvent	event;
	sfTime		fps;

	disp_list(ps);
	fps.microseconds = 100000;
	while (sfRenderWindow_isOpen(ps->win)) {
		while (sfRenderWindow_pollEvent(ps->win, &event)) {
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(ps->win);
		}
		sfSleep(fps);
	}
}

int main(int ac, char **av)
{
	pushswap_t	*ps = NULL;

	ps = init_pushswap(&ac, av);
	if (ps == NULL) {
		my_putchar('\n');
		return (0);
	}
	if (init_grap(ps) < 0)
		return (84);
	main_algo(ps, ac - 1);
	write(0, ps->buffer, ps->buf_siz);
	end(ps);
	return (0);
}

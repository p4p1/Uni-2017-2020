/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main file for the pushswap
*/

#include "pushswap.h"

static void disp_list(struct gear *list)
{
	int	is_sort = is_sorted(list);

	if (list == NULL) {
		my_printf("List is empty!\n");
		is_sort = 0;
	}
	while (list != NULL) {
		my_printf((list->next != NULL) ? "%d, " : "%d\n", list->value);
		list = list->next;
	}
	my_printf((is_sort)? "The list is sort!\n" : "The list isn't sort!\n");
}

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
	ps->buffer[ps->pos - 1] = '\0';
}

int main(int ac, char **av)
{
	pushswap_t	*ps = NULL;

	ps = init_pushswap(&ac, av);
	if (ps == NULL) {
		my_putchar('\n');
		return (0);
	}
	main_algo(ps, ac - 1);
	write(1, ps->buffer, ps->pos - 1);
	my_putchar('\n');
	if (ps->verbose)
		disp_list(ps->la);
	return (0);
}

/*
** EPITECH PROJECT, 2017
** current-file-name
** File description:
** <..>
*/

#include "matchstick.h"

static int valid_map(char **tab, int sz)
{
	int	no = 0;

	for (int i = 0; i < sz; i++) {
		for (int j = 0; tab[i][j] != '\0'; j++) {
			no = (tab[i][j] == '|') ? 1 : no;
		}
	}
	return (no);
}

int main(int ac, char **av)
{
	struct matchstick_s	*ms = init_matchstick(ac, av);
	int			rt = 0;

	if (ms == NULL)
		return (84);
	while (valid_map(ms->tab, ms->no_lines)) {
		display_map(ms->tab, ms->max_line_size);
		my_putchar('\n');
		if (user_play(ms) < 0)
			return (0);
		if (!valid_map(ms->tab, ms->no_lines))
			break;
		display_map(ms->tab, ms->max_line_size);
		my_putchar('\n');
		if (bot_play(ms) < 0)
			break;
	}
	display_map(ms->tab, ms->max_line_size);
	rt = destroy_matchstick(ms);
	return (rt);
}

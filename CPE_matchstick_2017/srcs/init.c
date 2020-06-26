/*
** EPITECH PROJECT, 2017
** init.c
** File description:
** <..>
*/

#include "matchstick.h"

static struct matchstick_s *create_tab(struct matchstick_s *ms)
{
	int	no = 1;
	int	i = 0;
	int	j = 0;

	ms->tab = (char **)malloc(sizeof(char *) * ms->no_lines + 8);
	if (ms->tab == NULL)
		return (NULL);
	for (i = 0; i < ms->no_lines; i++) {
		ms->tab[i] = (char *)malloc(sizeof(char) * (no + 1));
		if (ms->tab[i] == NULL)
			return (NULL);
		for (j = 0; j < no; j++)
			ms->tab[i][j] = '|';
		ms->tab[i][j] = '\0';
		no += 2;
	}
	ms->tab[i] = NULL;
	ms->max_line_size = no - 2;
	return (ms);
}

struct matchstick_s *init_matchstick(int ac, char **av)
{
	struct matchstick_s	*ms = malloc(sizeof(struct matchstick_s));

	if (ms == NULL)
		return (NULL);
	if (ac != 3) {
		my_printf("USAGE:\n\t%s [number] [number]\n", av[0]);
		return (NULL);
	}
	ms->no_lines = my_atoi(av[1]);
	if (ms->no_lines <= 1 || ms->no_lines >= 100) {
		my_printf("Number of matchsticks must be between 1 and 100\n");
		return (NULL);
	}
	ms->max_remove_no = my_atoi(av[2]);
	if (ms->max_remove_no < 0) {
		my_printf("Number of matchsticks must be over 0\n");
		return (NULL);
	}
	return (create_tab(ms));
}

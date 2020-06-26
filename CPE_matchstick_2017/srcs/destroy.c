/*
** EPITECH PROJECT, 2017
** destroy.c
** File description:
** <..>
*/

#include "matchstick.h"

int destroy_matchstick(struct matchstick_s *ms)
{
	int	i = 0;
	int	no = 0;

	for (i = 0; i < ms->no_lines; i++) {
		free(ms->tab[i]);
	}
	free(ms->tab);
	no = ms->rt;
	if (ms->rt == 1)
		my_printf("I lost... snif... but I'll get you next time!!\n");
	else
		my_printf("You lost, too bad...\n");
	free(ms);
	return (no);
}

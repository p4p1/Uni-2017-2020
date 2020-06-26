/*
** EPITECH PROJECT, 2017
** algo.c
** File description:
** <..>
*/

#include "matchstick.h"

static int sum_line(char **tab, int no_lines, int line)
{
	int	no = 0;

	if (line < 0 || line > no_lines)
		return (0);
	for (int i = 0; tab[line][i]; i++)
		if (tab[line][i] == '|')
			no++;
	return (no);
}

int sum_nim(char **tab, int no)
{
	int	sol = 0;

	if (tab == NULL|| no <= 0)
		return (-1);
	for (int i = 0; i < no; i++)
		sol ^= sum_line(tab, no, i);
	return (sol);
}

char **dup_tab(char **tab, int sz)
{
	char	**tmp = malloc(sizeof(char *) * sz + 8);
	int	i = 0;

	if (tmp == NULL)
		return (NULL);
	for (i = 0; i < sz && tab[i]; i++) {
		tmp[i] = my_strdup(tab[i]);
		if (tmp[i] == NULL)
			return (NULL);
	}
	tmp[i] = NULL;
	return (tmp);
}

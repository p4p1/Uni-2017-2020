/*
** EPITECH PROJECT, 2017
** match.c
** File description:
** <..>
*/

#include "matchstick.h"

int can_remove(struct matchstick_s *ms, int line, int match_no)
{
	int	no = 0;

	if (line < 0 || line >= ms->no_lines)
		return (0);
	for (int i = 0; ms->tab[line][i]; i++)
		if (ms->tab[line][i] == '|')
			no++;
	if (no < match_no)
		return (0);
	return (1);
}

void remove_match(struct matchstick_s *ms, int line, int no)
{
	int	pos = 0;

	if (!can_remove(ms, line, no))
		return;
	pos = my_strlen(ms->tab[line]) - 1;
	while (ms->tab[line][pos] == ' ')
		pos--;
	for (int i = 0; i < no; i++)
		ms->tab[line][pos - i] = ' ';
}

char **tmp_remove_match(struct matchstick_s *ms, int line, int no)
{
	int	pos = 0;
	char	**tab = dup_tab(ms->tab, ms->no_lines);

	if (tab == NULL || !can_remove(ms, line, no))
		return (NULL);
	pos = my_strlen(tab[line]) - 1;
	while (tab[line][pos] == ' ')
		pos--;
	for (int i = 0; i < no; i++)
		tab[line][pos - i] = ' ';
	return (tab);
}

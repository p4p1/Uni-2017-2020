/*
** EPITECH PROJECT, 2017
** user.c
** File description:
** <..>
*/

#include "matchstick.h"

static int invalid_line(struct matchstick_s *ms, char *str, int line)
{
	if (!(str[0] <= '9' && str[0] >= '0')) {
		my_printf("Error: invalid input (positive number expected)\n");
		return (1);
	}
	if (line >= 0 && line < ms->no_lines && !can_remove(ms, line, 1)) {
		my_printf("Error: this line is empty\n");
		return (1);
	}
	if (line >= 0 && line < ms->no_lines)
		return (0);
	my_printf("Error: this line is out of range\n");
	return (1);
}

static int valid_match_no(struct matchstick_s *ms, char *str, int line,
		int match)
{
	if (!(str[0] <= '9' && str[0] >= '0')) {
		my_printf("Error: invalid input (positive number expected)\n");
		return (1);
	}
	if (line < 0 || match <= 0) {
		my_printf("Error: you have to remove at least one match\n");
		return (1);
	}
	if (match >= 1 && match <= ms->max_remove_no &&
			!can_remove(ms, line, match)) {
		my_printf("Error: not enough matches on this line\n");
		return (1);
	}
	if (match >= 1 && match <= ms->max_remove_no)
		return (0);
	my_printf("Error: you cannot remove more than %d matches per turn\n",
			ms->max_remove_no);
	return (1);
}

static int exit_func(struct matchstick_s *ms, char *str, int line, int match)
{
	if (str != NULL) {
		free(str);
		remove_match(ms, line - 1, match);
		my_printf("Player removed %d match(es) from line %d\n", match,
				line);
		ms->rt = AI;
	}
	return ((str == NULL) ? -1 : 0);
}

int user_play(struct matchstick_s *ms)
{
	char	*str = (char *)malloc(sizeof(char) * BUFSIZ);
	int	line = 0;
	int	match = 0;

	if (str == NULL)
		return (-1);
	my_printf("Your turn:\n");
	do {
		my_printf("Line: ");
		str = my_fgets(str, BUFSIZ, 0);
		line = my_atoi(str);
	} while (str != NULL && invalid_line(ms, str, line - 1));
	if(str == NULL)
		return (-1);
	do {
		my_printf("Matches: ");
		str = my_fgets(str, BUFSIZ, 0);
		match = my_atoi(str);
	} while (str != NULL && valid_match_no(ms, str, line - 1, match));
	return (exit_func(ms, str, line, match));
}

/*
** EPITECH PROJECT, 2017
** bot.c
** File description:
** <..>
*/

#include "matchstick.h"

static int invalid_line(struct matchstick_s *ms, int line)
{
	if (!can_remove(ms, line, 1)) {
		return (1);
	}
	if (line >= 0 && line < ms->no_lines) {
		return (0);
	}
	return (1);
}

static int valid_match_no(struct matchstick_s *ms, int line, int match)
{
	if (!can_remove(ms, line, match)) {
		return (1);
	}
	if (match >= 1 && match <= ms->max_remove_no) {
		return (0);
	}
	return (1);
}

static int exit_func(struct matchstick_s *ms, struct pos ps)
{
	remove_match(ms, ps.line, ps.no_match);
	my_printf("AI removed %d match(es) from line %d\n", ps.no_match,
			ps.line + 1);
	ms->rt = USER;
	return (0);
}

static int can_place(struct matchstick_s *ms, struct pos ps)
{
	char	**tab = NULL;

	if (invalid_line(ms, ps.line) && valid_match_no(ms,
				ps.line, ps.no_match))
		return (1);
	if ((tab = tmp_remove_match(ms, ps.line, ps.no_match)) == NULL)
		return (1);
	if (sum_nim(tab, ms->no_lines) != 0)
		return (0);
	return (1);
}

int bot_play(struct matchstick_s *ms)
{
	struct pos	ps = {0, ms->max_remove_no};

	my_printf("AI's turn...\n");
	while (can_place(ms, ps)) {
		ps.no_match--;
		if (ps.no_match == 0) {
			ps.no_match = ms->max_remove_no;
			ps.line++;
		}
		if (ps.line > ms->no_lines) {
			ps = infi(ms, ps);
			break;
		}
	}
	return (exit_func(ms, ps));
}

/*
** EPITECH PROJECT, 2017
** infi.c
** File description:
** <..>
*/

#include "matchstick.h"

struct pos infi(struct matchstick_s *ms, struct pos ps)
{
	ps.line = 0;
	while (ps.line < ms->no_lines) {
		if (can_remove(ms, ps.line, 1))
			break;
		ps.line++;
	}
	ps.no_match = 1;
	return (ps);
}

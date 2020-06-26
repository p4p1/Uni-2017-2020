/*
** EPITECH PROJECT, 2017
** lex.c
** File description:
** <..>
*/

#include "corewar.h"

struct d_queue *lex_file(char *fname)
{
	struct d_queue	*qu = NULL;
	int		fd = open(fname, O_RDONLY);

	if (fd < 0)
		cant_open();
	return (qu);
}

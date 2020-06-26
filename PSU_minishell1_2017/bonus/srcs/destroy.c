/*
** EPITECH PROJECT, 2017
** destroy.c
** File description:
** destroy the minishell struct
*/

#include "minishell.h"

static void free_clist(struct queue *qu)
{
	if (qu->next != NULL)
		free_clist(qu->next);
	free(qu->token);
	free(qu);
}

void destroy_shell(struct shell_info *si)
{
	if (si != NULL) {
		free_clist(si->envi);
		free(si->prompt);
		free(si->token_type);
		free(si);
	}
}

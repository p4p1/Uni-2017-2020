/*
** EPITECH PROJECT, 2017
** destroy.c
** File description:
** <..>
*/

#include "minishell.h"

int destroy_shell(struct shell_info *si)
{
	if (si != NULL)
		return (0);
	destroy_prompt(si);
	if (si->pwd != NULL)
		free(si->pwd);
	if (si->path != NULL)
		free(si->path);
	return (0);
}

/*
** EPITECH PROJECT, 2017
** prompt.c
** File description:
** <..>
*/

#include "prompt.h"

void create_prompt(struct shell_info *si)
{
	if (si != NULL && si->prompt == NULL)
		si->prompt = my_strdup(PROMPT);
}

void display_prompt(struct shell_info *si)
{
	if (si != NULL && si->prompt != NULL)
		write(1, si->prompt, my_strlen(si->prompt));
}

void change_prompt(struct shell_info *si, char *new_prompt)
{
	if (si != NULL && new_prompt != NULL) {
		free(si->prompt);
		si->prompt = my_strdup(new_prompt);
	}
}

void destroy_prompt(struct shell_info *si)
{
	if (si != NULL && si->prompt != NULL)
		free(si->prompt);
}

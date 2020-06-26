/*
** EPITECH PROJECT, 2017
** prompt.h
** File description:
** prompt header file
*/

#ifndef PROMPT_H_
#define PROMPT_H_

#include "minishell.h"

struct shell_info;

void create_prompt(struct shell_info *);
void destroy_prompt(struct shell_info *);
void display_prompt(struct shell_info *);
void change_prompt(struct shell_info *, char *);

#endif

/*
** EPITECH PROJECT, 2017
** init.c
** File description:
** minishell initialization function
*/

#include "minishell.h"

struct shell_info *init_shell(char **env)
{
	struct shell_info	*si = malloc(sizeof(struct shell_info));

	if (si == NULL)
		return (NULL);
	si->prompt = my_strdup(PROMPT);
	if (si->prompt == NULL)
		return (NULL);
	si->token = NULL;
	si->token_type = NULL;
	for (int i = 0; env[i]; i++)
		add_queue(&si->envi, my_strdup(env[i]));
	si->get_command = &get_cmd_fp;
	si->process_command = &proc_cmd_fp;
	return (si);
}

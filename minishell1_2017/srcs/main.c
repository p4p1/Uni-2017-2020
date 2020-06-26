/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** minishell main file
*/

#include "minishell.h"

int main(int ac, char **av)
{
	struct shell_info	*si = init_shell();
	char			buf[1024];

	if (si == NULL)
		return (84);
	while (si->in_shell) {
		display_prompt(si);
		si->in_shell = read(0, buf, 1024);
	}
	destroy_shell(si);
	return (0);
}

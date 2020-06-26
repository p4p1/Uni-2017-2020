/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main file for the minishell
*/

#include "minishell.h"

static void usage(char *name)
{
	my_printf("%s\n", name);
}

static int process_arg(char ch, char *name)
{
	if (ch == 'h') {
		usage(name);
		return (0);
	}
	if (ch == '?')
		return (84);
	return (1);
}

int main(int ac, char **av, char **env)
{
	struct shell_info	*si = init_shell(env);
	char			*buffer = NULL;
	int			ret = 0;

	if (si == NULL)
		return (84);
	while ((ret = my_getopt(ac, av, "h")) != -1)
		if ((ret = process_arg(ret, av[0])) != 1)
			return (ret);
	while (1) {
		buffer = si->get_command(si);
		if (buffer == NULL)
			break;
		si->process_command(si);
	}
	destroy_shell(si);
	return (0);
}

/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** <..>
*/

#include "minishell2.h"

static int usage(char *fname)
{
	my_printf("%s: Usage\n", fname);
	return (0);
}

static int line_loop(int verb, struct queue *env)
{
	char	*line = NULL;
	int	ret = 0;
	token_t	*tree = NULL;

	do {
		my_printf(PROMPT);
		line = gnl(0);
		if (line == NULL) {
			my_printf("exit\n");
			break;
		}
		tree = create_tree(line);
		if (verb)
			disp_tree(tree);
		ret = parser(tree, &env, verb);
	} while (line);
	return (ret);
}

static int catch_opt(int ch, char *fname, int *verb)
{
	if (ch == 'h')
		return (usage(fname));
	if (ch == 'v')
		*verb = 1;
	if (ch == '?')
		return (84);
	return (-1);
}

int main(int ac, char **av, char **env)
{
	int	ch = 0;
	int	verb = 0;
	struct queue	*envi = NULL;

	for (int i = 0; env[i]; i++)
		envi = add_queue(envi, my_strdup(env[i]));
	while ((ch = my_getopt(ac, av, "hv")) != -1)
		if ((ch = catch_opt(ch, av[0], &verb)) != -1)
			return (ch);
	return (line_loop(verb, envi));
}

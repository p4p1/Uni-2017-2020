/*
** EPITECH PROJECT, 2017
** parser.c
** File description:
** <..>
*/

#include "minishell2.h"

int parser(token_t *tree, struct queue **env, int verb)
{
	int	no = 0;

	if (verb)
		my_printf("Currently at node: %p, env: %p\n", tree, env);
	if (tree->type == COMMAND)
		no = ex_command(tree, env);
	if (tree->type == SEPARATORS) {
		if (tree->left)
			no = parser(tree->left, env, verb);
		if (tree->right)
			no = parser(tree->right, env, verb);
	}
	return (no);
}

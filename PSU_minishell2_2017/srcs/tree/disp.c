/*
** EPITECH PROJECT, 2017
** disp.c
** File description:
** <..>
*/

#include "minishell2.h"

void disp_tree(token_t *tree)
{
	if (tree == NULL)
		return;
	my_printf("Current_node: %p\n", tree);
	my_printf("Tab Value:\n");
	for (int i = 0; tree->val[i]; i++)
		my_printf("tab[%d]: %s\n", i, tree->val[i]);
	if (tree->right)
		disp_tree(tree->right);
	if (tree->left)
		disp_tree(tree->left);
}

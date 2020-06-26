/*
** EPITECH PROJECT, 2017
** tree.c
** File description:
** <..>
*/

#include "minishell2.h"

static char **extract_tab(char *str, int *pos)
{
	char	**tab = malloc(sizeof(char *) * (count_args(str + *pos) + 8));
	int	args = count_args(str);
	int	no = 0;
	int	i = 0;

	for (i = 0; i < args && *pos < my_strlen(str); i++) {
		*pos += skip_tabs_space(str + *pos);
		tab[no] = my_strdup_ln(str + *pos, next_arg(str + *pos));
		*pos += next_arg(str + *pos);
		if (tab[no] == NULL)
			return (NULL);
		++no;
	}
	tab[i] = NULL;
	return (tab);
}

static char **get_separator(char *str, int *pos)
{
	char	**tab = malloc(sizeof(char *) * 2);
	int	inc = 0;

	if (tab == NULL)
		return (NULL);
	for (inc = 0; str[*pos + inc] && is_separator(str[*pos + inc]); inc++);
	tab[0] = my_strdup_ln(str + *pos, inc);
	tab[1] = NULL;
	*pos += inc;
	return (tab);
}

static token_t *set_head(token_t *cur, token_t **head)
{
	token_t	*tree = malloc(sizeof(token_t));

	if (tree == NULL)
		return (NULL);
	my_memset(tree, 0, sizeof(token_t));
	tree->right = malloc(sizeof(token_t));
	if (tree->right == NULL)
		return (NULL);
	tree->left = cur;
	if ((*head)->type != SEPARATORS)
		*head = tree;
	return (tree);
}

static token_t *set_separator(token_t *tree, token_t **head, char *str,
		int *pos)
{
	tree = set_head(tree, head);
	if (tree == NULL)
		return (NULL);
	tree->type = SEPARATORS;
	tree->val = get_separator(str, pos);
	tree = tree->right;
	return (tree);
}

token_t *create_tree(char *str)
{
	token_t	*tree = malloc(sizeof(token_t));
	token_t	*head = tree;
	int	pos = 0;

	if (tree == NULL)
		return (NULL);
	my_memset(tree, 0, sizeof(token_t));
	while (pos < my_strlen(str)) {
		pos += skip_tabs_space(str + pos);
		if (is_separator(str[pos]))
			tree = set_separator(tree, &head, str, &pos);
		if (tree == NULL)
			return (NULL);
		tree->type = COMMAND;
		tree->val = extract_tab(str, &pos);
	}
	return (head);
}

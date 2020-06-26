/*
** EPITECH PROJECT, 2017
** eval_expr.c
** File description:
** the main file for the eval_expr
*/

#include "bistro.h"

static char *set_to_zero(void)
{
	char	*tmp = (char *)malloc(sizeof(char) * 2);

	tmp[0] = '0';
	tmp[1] = '\0';
	return (tmp);
}

static char *po(char token, char *no1, char *no2, char **b_o)
{
	char	*(*fp[])(char *, char *, char const *, char const *) = {
		&addinf_2, &subinf_2, &multinf, &divinf_2, &modulo_2, 0};
	int	i = 0;

	if (no1 == 0)
		no1 = set_to_zero();
	if (no2 == 0)
		no2 = set_to_zero();
	while (fp[i] != 0 && b_o[1][i] != '\0') {
		if (token == b_o[1][i]) {
			return (fp[i](dump_z(no1, b_o[0]), dump_z(no2, b_o[0]),
						b_o[0], (*(b_o + 1) - 2)));
		}
		++i;
	}
	return (0);
}

static int check_op_expr(char *str, char const *ops)
{
	if (my_strlen(str) == 1 && check_op(str, ops))
		return (1);
	return (0);
}

static char **create_table(char const *ops, char const *base)
{
	char	**str = (char **)malloc(sizeof(char*) * 3);

	str[0] = my_strdup(base);
	str[1] = my_strdup(ops);
	str[2] = 0;
	return (str);
}

char *eval_expr(char const *base, char const *ops, char const *expr,
		unsigned int size)
{
	struct queue	*q;
	struct stack	*s = 0;
	char	*no1 = 0;
	char	*no2 = 0;

	if (expr == 0 || check_expr(ops, base, (char *)expr))
		return (0);
	q = shuting_yard(del_space(expr, base, ops), create_table(ops, base));
	while (q != NULL) {
		if (check_op_expr(q->token, ops) && s != 0) {
			no1 = pop_stack(&s);
			no2 = pop_stack(&s);
			add_stack(&s, po(*q->token, no2, no1,
						create_table((ops + 2), base)));
		} else {
			add_stack(&s, q->token);
		}
		q = q->next;
	}
	size++;
	return (pop_stack(&s));
}

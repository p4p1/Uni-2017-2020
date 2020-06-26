/*
** EPITECH PROJECT, 2017
** error.c
** File description:
** error detection file
*/

#include "bistro.h"

static int in_base_and_op(char const *ops, char const *base, char ch)
{
	int	i = 0;

	while (base[i] != '\0') {
		if (base[i] == ch)
			return (1);
		i++;
	}
	i = 0;
	while (ops[i] != '\0') {
		if (ops[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

static int v_check_expr(char const *ops, char const *base, char *expr)
{
	if (in_base_and_op(ops, base, *expr)) {
		if (in_base(*expr, base) && check_op(expr + 1, ops + 2))
			return (v_check_expr(ops, base, expr + 1));
		if (in_base(*expr, base) && in_base(*(expr + 1), base))
			return (v_check_expr(ops, base, expr + 1));
		if (check_op(expr, (ops + 2)) && in_base(*(expr + 1), base))
			return (v_check_expr(ops, base, expr + 1));
		if (check_op(expr, ops + 2) && expr[1] == '\0')
			return (1);
		if (in_base(*expr, base) && expr[1] == *ops)
			return (1);
		if (check_op(expr, ops + 2) && check_op(expr + 1, ops + 2) &&
				*(expr+1) != ops[3]) {
			return (1);
		}
		return (0);
	}
	return (1);
}

static int check_par(char *expr, char const *ops)
{
	int	i = 0;
	int	p = 0;

	while (expr[i] != '\0') {
		if (expr[i] == *ops)
			p++;
		if (expr[i] == ops[1])
			p--;
		++i;
	}
	if (p)
		return (1);
	return (0);
}

int check_expr(char const *ops, char const *base, char *expr)
{
	int	t_var = 0;
	int	i = 0;

	while (expr[i] != '\0') {
		if (check_op((expr + i), ops + 2) && !in_base(expr[i], base)) {
			++i;
		} else {
			--i;
			break;
		}
	}
	if (i < 0)
		i = 0;
	if (expr[i] != '\0') {
		t_var += v_check_expr(ops, base, expr + i);
		t_var += check_par(expr + i, ops);
	} else {
		t_var = 1;
	}
	return (t_var);
}

void error_excpetion(void)
{
	my_putstr(ERROR_MSG);
	exit(OP_DIV_IDX);
}

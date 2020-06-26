/*
** EPITECH PROJECT, 2017
** check.c
** File description:
** check if character send is in base or operators
*/

#include "bistro.h"

int check_op(char *op, char const *op_str)
{
	int	i = 0;
	int	power = 1;

	while (op_str[i] != '\0') {
		if (*op == op_str[i])
			return (power);
		if (i % 2)
			power += 2;
		i++;
	}
	return (0);
}

static char *trunk_ops(char *expr, char const *base, char const *ops)
{
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
	return (expr + i);
}

char *del_space(char const *src, char const *base, char const *ops)
{
	char	*str;
	int	i = -1;
	int	j = 0;

	str = (char *)malloc(sizeof(char) * (my_strlen(src) + 1));
	if (str == 0) {
		my_putstr(ERROR_MSG);
		exit(EXIT_MALLOC);
	}
	while (src[++i]) {
		if (src[i] != ' ')
			str[j++] = src[i];
	}
	str[j] = '\0';
	str = trunk_ops(str, base, ops);
	return (str);
}

int in_base(char op, char const *base)
{
	int	i = 0;

	while (base[i] != '\0') {
		if (op == base[i])
			return (1);
		++i;
	}
	return (0);
}

int neg_no(char *str, int i, char const *base, char const *op)
{
	if (in_base(*(str + 1), base)) {
		if (*str == op[3] && i == 0)
			return (1);
		if (*str == op[3] && i > 0 && check_op((str - 1), op))
			return (1);
		if (*str == op[3] && i > 0 && *(str - 1) == *op)
			return (1);
	}
	return (0);
}

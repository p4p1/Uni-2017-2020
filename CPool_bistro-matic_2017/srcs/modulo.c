/*
** EPITECH PROJECT, 2017
** mnodulo.c
** File descirption:
** Infinite modulo
*/
#include "bistro.h"

char *modulo_div(char *s1, char *s2, char const *base)
{
	char		*result;
	int		j = 0;
	struct operands	op;

	init_op(&op, s1, s2, my_strlen(s1) + 1);
	result = malloc(sizeof(char) * (op.size));
	my_memset(result, op.size);
	for (int i = 0; is_bigger(op.op1, op.op2, base, 0) == 1; ++i) {
		if (is_bigger(op.op1, op.op2, base, my_strlen(op.op2)
		+ j) == 1) {
			result[i] = to_base(do_division(&op, base, j), base);
			if (check_exception(result, op.op1, base) == 1)
				return (my_strdup("0"));
			j = 0;
		} else {
			--i;
			++j;
		}
	}
	return (s1);
}

static char *modulo_negatives(char **s1, char **s2, char const *op, int *neg)
{
	if (check_neg(*s1, op[3]) < 0 && check_neg(*s2, op[3]) > 0) {
		*(s1) = *(s1) + 1;
		*neg = *neg + 1;
		return (*s1);
	}
	else if (check_neg(*s2, op[3]) < 0 && check_neg(*s1, op[3]) > 0) {
		*(s2) = *(s2) + 1;
		return (*s2);
	}
	return (NULL);
}

char *modulo(char *s1, char *s2, char const *base, char const *op)
{
	char	*result;
	int	neg = 0;

	result = malloc(sizeof(char) * 2);
	result[1] = '\0';
	if (check_neg(s1, op[3]) < 0 && check_neg(s2, op[3]) < 0)
		++neg;
	modulo_negatives(&s1, &s2, op, &neg);
	if (len(s2) > len(s1) || (len(s1) == len(s2)
	&& cmp_base(s1, s2, base) < 0))
		result[0] = base[0];
	else if (len(s1) == len(s2) && cmp_base(s1, s2, base) == 0) {
		result[0] = base[1];
		return (my_strdup(result));
	} else {
		result = modulo_div(s1, s2, base);
	}
	if (neg > 0)
		result = negatives(result, op);
	return (result);
}

char *modulo_2(char *s1, char *s2, char const *base, char const *op)
{
	if (check_neg(s1, op[3]) < 0 && check_neg(s2, op[3]) < 0)
		return (modulo(s1 + 1, s2 + 1, base, op));
	if (check_neg(s1, op[3]) > 0 && check_neg(s2, op[3]) < 0)
		return (modulo(s1, s2 + 1, base, op));
	else if (s2[0] == base[0]) {
		zero_exception();
	}
	return (modulo(s1, s2, base, op));
}

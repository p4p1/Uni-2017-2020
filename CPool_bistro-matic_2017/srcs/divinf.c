/*
** EPITECH PROJECT, 2017
** divinf.c
** File descirption:
** infinite divisions
*/
#include "bistro.h"

int is_bigger(char *s1, char *s2, char const *base, int n)
{
	const int	len1 = my_strlen(s1);
	const int	len2 = my_strlen(s2);

	if (n == 0 && (len1 > len2 || (len1 == len2
		&& cmp_base(s1, s2, base) > 0)))
		return (1);
	if (n != 0 && ((cmp_base_n(s1, s2, base, n) >= 0 && n == len2)
	|| n > len2))
		return (1);
	return (0);
}

int do_division(struct operands *op, char const *base, int j)
{
	int calc = 0;

	op->tmp = n_mult(op, &calc, base, j);
	if (cmp_base_n(op->tmp, op->op1, base, my_strlen(op->tmp)) != 0)
		op->save = my_strndup(op->op1, my_strlen(op->tmp) + j);
	else
		op->save = my_strndup(op->op1, my_strlen(op->tmp));
	op->tmp = subinf(op->save, op->tmp, base);
	my_strcpy_div(op->op1, op->tmp);
	my_strcpy(op->op1 + my_strlen(op->tmp), op->op1 + my_strlen(op->save));
	return (calc);
}

char *divide(char *s1, char *s2, char const *base)
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
				return (result);
			j = 0;
		} else {
			--i;
			++j;
		}
	}
	return (result);
}

char *divinf(char *s1, char *s2, char const *base, char const *op)
{
	char	*result;
	int	neg = 0;

	result = malloc(sizeof(char) * 2);
	result[1] = '\0';
	if (check_neg(s1, op[3]) < 0 || check_neg(s2, op[3]) < 0)
		++neg;
	checking_negatives(&s1, &s2, op);
	if (my_strlen(s2) > my_strlen(s1) || (my_strlen(s1) == my_strlen(s2)
	&& cmp_base(s1, s2, base) < 0))
		result[0] = base[0];
	else if (len(s1) == len(s2) && cmp_base(s1, s2, base) == 0) {
		result[0] = base[1];
		return (my_strdup(result));
	}
	else
		result = divide(s1, s2, base);
	if (neg > 0)
		result = negatives(result, op);
	return (result);
}

char *divinf_2(char *s1, char *s2, char const *base, char const *op)
{
	if (check_neg(s1, op[3]) < 0 && check_neg(s2, op[3]) < 0)
		return (divinf(s1 + 1, s2 + 1, base, op));
	else if (s2[0] == base[0]) {
		zero_exception();
	}
	return (divinf(s1, s2, base, op));
}

/*
** EPITECH PROJECT, 2017
** utils.3
** File descirption:
** Utils functions
*/
#include "bistro.h"

int zero_condition(char *s1, char *s2, char const *base)
{
	return ((my_strlen(s1) == 1 && s1[0] == base[0]) ||
			(s2[0] == base[0] && my_strlen(s2) == 1));
}

char	*my_strndup(char const *src, int n)
{
	char	*dest = malloc(sizeof(char*) * n + 1);
	int	i = 0;

	if (dest == NULL)
		return (NULL);
	while (i < n && src[i] != '\0') {
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char *n_mult(struct operands *op, int *nb, char const *base, int j)
{
	char *count = my_strdup(op->op2);
	char *tmp;

	*nb = 0;
	for (int i = 1; is_bigger(op->op1, count, base, my_strlen(op->op2) + j)
	== 1; ++i) {
		tmp = count;
		count = addinf(count, op->op2, base);
		*nb = *nb + 1;
	}
	if (cmp_base_n(count, op->op1, base, my_strlen(count)) == 0) {
		*nb = *nb + 1;
		return (count);
	}
	return (tmp);
}

int check_exception(char *result, char *s1, const char *base)
{
	int i;

	for (i = 0; s1[i]; ++i) {
		if (s1[i] != base[0])
			return (0);
	}
	my_strcat(result, s1 + 1);
	return (1);
}

void init_op(struct operands *op, char *s1, char *s2, int size)
{
	op->op1 = s1;
	op->op2 = s2;
	op->size = size;
}

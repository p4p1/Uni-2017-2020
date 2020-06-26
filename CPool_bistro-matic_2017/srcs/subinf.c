/*
** EPITECH PROJECT, 2017
** subbinf.c
** File description:
** Infinte substraction
*/
#include "bistro.h"

static void my_remainder(char *result, int i, int len, char const *base)
{
	int	j = 0;
	int rem = 0;

	while (result[i + j + 1] == base[0]) {
		++j;
	}
	while (j >= 0) {
		result[i + j + 1] = base[from_base(result[i + j + 1], base)
		+ rem - 1];
		rem = len;
		--j;
	}
}

static char *sub(char *s1, char *s2, char const *base)
{
	int		calc = 0;
	char		*result = my_strdup(s1);
	const int	len = my_strlen(base);
	int		rem = 0;

	for (int i = 0; s2[i]; ++i) {
		if (from_base(result[i], base) < from_base(s2[i], base)) {
			my_remainder(result, i, len, base);
			rem = len;
		}
		calc = from_base(result[i], base) + rem
		- from_base(s2[i], base);
		result[i] = to_base(calc, base);
		rem = 0;
	}
	return (my_revstr(result));
}

char *subinf(char *s1, char *s2, char const *base)
{
	char	*result;

	if (my_strlen(s1) > my_strlen(s2)) {
		result = sub(my_revstr(s1), my_revstr(s2), base); }
	else if (my_strlen(s1) == my_strlen(s2)) {
		if (cmp_base(s1, s2, base) > 0) {
			result = sub(my_revstr(s1), my_revstr(s2), base);
		} else
			result = sub(my_revstr(s2), my_revstr(s1), base);
	}
	else
		result = sub(my_revstr(s2), my_revstr(s1), base);
	delete_zeros(result, base);
	my_revstr(s1);
	my_revstr(s2);
	return (result[0] == '0' && result[1] != 0 ? result + 1 : result);
}

char *subinf_2(char *s1, char *s2, char const *base, char const *op)
{
	if (check_neg(s1, op[3]) < 0 && check_neg(s2, op[3]) < 0) {
		return (put_minus(addinf_2(s1 + 1, s2, base, op),
					base, op));
	}
	if (check_neg(s1, op[3]) < 0 && check_neg(s2, op[3]) > 0)
		return (put_minus(addinf_2(s1 + 1, s2, base, op), base, op));
	if (cmp_base(s1, s2, base) < 0 && my_strlen(s1) == my_strlen(s2))
		return (put_minus(subinf(s1, s2, base), base, op));
	if (my_strlen(s1) < my_strlen(s2) && cmp_base(s1, s2, base) <= 0)
		return (put_minus(subinf(s1, s2, base), base, op));
	return (subinf(s1, s2, base));
}

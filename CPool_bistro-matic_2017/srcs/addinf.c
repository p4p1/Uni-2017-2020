/*
** EPITECH PROJECT, 2017
** <..>
** File description:
** <...>
*/
#include "bistro.h"

static char *add(char *s1, char *s2, char const *base)
{
	char		*result = str_malloc(s1, s2);
	int		calc = 0;
	const int	len = my_strlen(s2);

	my_memset(result, my_strlen(s1) + 3);
	for (int i = 0; s1[i]; ++i) {
		if (i < len) {
			calc = from_base(s1[i], base) + from_base(s2[i], base)
			+ from_base(result[i], base);
		}
		else {
			calc = from_base(s1[i], base)
			+ from_base(result[i], base);
		}
		result[i] = to_base(calc % my_strlen(base), base);
		result[i + 1] = to_base(calc / my_strlen(base)
		+ from_base(result[i + 1], base), base);
	}
	return (my_revstr(result));
}

char *addinf(char *s1, char *s2, char const *base)
{
	char	*result = NULL;

	s1 = my_revstr(s1);
	s2 = my_revstr(s2);
	if (my_strlen(s1) > my_strlen(s2))
		result = add(s1, s2, base);
	else
		result = add(s2, s1, base);
	my_revstr(s1);
	my_revstr(s2);
	delete_zeros(result, base);
	return (result[0] == '-' ? result + 1 : result);

}

char  *addinf_2(char *s1, char *s2, char const *base, char const *op)
{
	if (check_neg(s1, op[3]) < 0 && check_neg(s2, op[3]) < 0) {
		return (put_minus(addinf(s1 + 1, s2 + 1, base), base, op));
	}
	if (check_neg(s1, op[3]) > 0 && check_neg(s2, op[3]) < 0) {
		if (cmp_base(s2 + 1, s1, base) < 0 &&
				my_strlen(s2 + 1) <= my_strlen(s1)) {
			return (subinf(s1, s2 + 1, base));
		}
		return (put_minus(subinf(s1, s2 + 1, base), base, op));
	}
	if (check_neg(s1, op[3]) < 0 && check_neg(s2, op[3]) > 0) {
		if (my_strlen(s1 + 1) < my_strlen(s2)) {
			return (subinf(s1 + 1, s2, base));
		}
		return (put_minus(subinf(s1 + 1, s2, base), base, op));
	}
	return (addinf(s1, s2, base));
}

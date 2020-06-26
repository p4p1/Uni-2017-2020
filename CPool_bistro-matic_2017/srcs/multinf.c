/*
** EPITECH PROJECT, 2017
** multinf.c
** File descirption:
** Infinte multiplications
*/
#include "bistro.h"

static char *strdup_zero(char const *base)
{
	char	*tmp = (char *)malloc(sizeof(char) * 2);

	tmp[0] = base[0];
	tmp[1] = '\0';
	return (tmp);
}

static char *mult(char *s1, char *s2, char const *base)
{
	const int	size = my_strlen(s1) + my_strlen(s2) + 1;
	char		*result = malloc(sizeof(char) * (size));
	int		calc = 0;

	if (zero_condition(s1, s2, base)) {
		return (strdup_zero(base));
	}
	my_memset(result, size);
	for (int i = 0; s1[i]; ++i) {
		for (int j = 0; s2[j]; ++j) {
			calc = from_base(s1[i], base) * from_base(s2[j], base)
			+ from_base(result[i + j], base);
			result[i + j] = to_base(calc % my_strlen(base), base);
			result[i + 1 + j] = to_base(calc / my_strlen(base), base)
			+ from_base(result[i + j + 1], base);
		}
	}
	my_revstr(result);
	if (result[0] == '0' && my_char_is_num(result[1]) == 1)
		return (result + 1);
	return (result);
}

char *negatives(char *result, char const *op)
{
	char	*tmp = malloc(sizeof(char) * (my_strlen(result) + 2));

	if (tmp == NULL)
		return (NULL);
	tmp += 1;
	tmp[0] = op[3];
	my_strcpy(tmp + 1, result);
	return (tmp);
}

char *checking_negatives(char **s1, char **s2, char const *op)
{
	if (check_neg(*s1, op[3]) < 0 && check_neg(*s2, op[3]) > 0) {
		*(s1) = *(s1) + 1;
		return (*s1);
	}
	else if (check_neg(*s2, op[3]) < 0 && check_neg(*s1, op[3]) > 0) {
		*(s2) = *(s2) + 1;
		return (*s2);
	}
	return (NULL);
}

char *multinf(char *s1, char *s2, char const *base, char const *op)
{
	char	*result;
	int	neg = 0;

	if (check_neg(s1, op[3]) < 0 && check_neg(s2, op[3]) < 0) {
		s1 = s1 + 1;
		s2 = s2 + 1;
	}
	if (check_neg(s1, op[3]) < 0 || check_neg(s2, op[3]) < 0)
		++neg;
	checking_negatives(&s1, &s2, op);
	s1 = my_revstr(s1);
	s2 = my_revstr(s2);
	if (my_strlen(s1) > my_strlen(s2))
		result = mult(s1, s2, base);
	else
		result = mult(s2, s1, base);
	if (neg > 0)
		result = negatives(result, op);
	return (result);
}
/*
** EPITECH PROJECT, 2017
** utils_2.c
** File descirption:
** Utils functions
*/
#include "bistro.h"

int	cmp_base(char *s1, char *s2, char const *base)
{
	int	i = 0;
	char	j;

	while (s1[i] == s2[i] && (s1[i] && s2[i]))
		++i;
	j = from_base(s1[i], base) - from_base(s2[i], base);
	return (j);
}

int	cmp_base_n(char *s1, char *s2, char const *base, int n)
{
	int	i = 0;
	char	j;

	while (s1[i] == s2[i] && (s1[i] && s2[i]) && i < n)
		++i;
	j = from_base(s1[i], base) - from_base(s2[i], base);
	if (i == n)
		return (0);
	return (j);
}

char	*my_strcpy_div(char *dest, char const *src)
{
	int i = 0;

	while(src[i]) {
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char *put_minus(char *result, char const *base, char const *op)
{
	char	*tmp = malloc(sizeof(char) * (my_strlen(result) + 2));

	if (result[0] == base[0] && result[1] == 0)
		return (result);
	delete_zeros(result, base);
	if (tmp == NULL)
		return (NULL);
	tmp[0] = op[3];
	my_strcpy(tmp + 1, result);
	return (tmp);
}

void delete_zeros(char *result, char const *base)
{
	int	i = 0;
	while (result[i] == base[0] && result[i + 1] != '\0')
		++i;
	my_strcpy(result, result + i);
}
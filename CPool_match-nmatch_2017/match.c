/*
** EPITECH PROJECT, 2017
** match
** File description:
** find if two strings match.
*/

#include <stdio.h>

void my_putchar(char c);

int get_str_len(char const *str)
{
	int	len = 0;

	while (*(str+len) != '\0')
		len++;
	return (len);
}

int check_equality(char c1, char c2, int *flag)
{
	if (c1 == c2)
		return (1);
	if (c2 == '*') {
		*flag = 1;
		return (1);
	}
	if (*flag && (c1 == c2)) {
		*flag = 0;
		return (1);
	}
	if (*flag)
		return (1);
	return (0);
}

int match(char const *s1, char const *s2)
{
	int	len_s1 = get_str_len(s1);
	int	len_s2 = get_str_len(s2);
	int	len = (len_s1 < len_s2) ? len_s2 : len_s1;
	int	i = 0;
	int	flag = 0;
	int	done = 1;

	if (s1 == 0 || s2 == 0)
		return (0);
	while (done && i < len) {
		done = check_equality(*(s1+i), *s2, &flag);
		if (*s2 == '*')
			++s2;
		if (!flag)
			++s2;
		i += 1;
	}
	if (i < len)
		return (0);
	else
		return (1);
}


/*
** EPITECH PROJECT, 2017
** add_values.c
** File description:
** add value of the two given strings
*/

#include "infin_add.h"

static int do_op(char *s1, char *s2, int ret, int si1, int si2)
{
	int		value = 0;

	if ((si1 == -1) && (si2 == -1))
		ret *= -1;
	if ((si1 == -1 || si2 == -1) && !(si1 == -1 && si2 == -1))
		value = ((ch_to_i(*s1) - ret) * si1) + (ch_to_i(*s2) * si2);
	else
		value = (ch_to_i(*s1) * si1) + (ch_to_i(*s2) * si2) +
						(si1 * si2 *ret);
	if ((si1 == -1 || si2 == -1) && !(si1 == -1 && si2 == -1) &&
			(ch_to_i(*s1) < ch_to_i(*s2) && my_strlen(s1) > 1)) {
		if (value > 0)
			value *= -1;
		return ((value == 0)? 0 : 10 + (value + 10));
	}
	if (value < 0)
		return (-1 * (value));
	return (value);
}

void inc(char **str1, char **str2)
{
	if (**str2 != '\0')
		*str2 += 1;
	if (**str1 != '\0')
		*str1 += 1;
}

char *add_values(char *str1, char *str2, int sign1, int sign2)
{
	int	length = my_strlen(str1);
	char	*result = 0;
	int	ret = 0;
	int	i = 0;

	if (my_strlen(str2) > length)
		length = my_strlen(str2);
	result = malloc(length * sizeof(char) + 2);
	do {
		ret = do_op(str1, str2, ret, sign1, sign2);
		*(result + i) = i_to_ch(ret % 10);
		ret /= 10;
		inc(&str1, &str2);
	} while (++i < length);
	if (ret == 1)
		*(result + i++) = '1';
	*(result + i) = '\0';
	return (result);
}

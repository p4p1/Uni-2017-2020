/*
** EPITECH PROJECT, 2017
** my_str_isalpha.c
** File description:
** return 1 is str is alpha
*/

int my_str_isalpha(char const *str)
{
	int	len = 0;
	int	i = 0;

	if (str == 0)
		return (0);
	while (*(str+len) != '\0')
		++len;
	while (*str != '\0') {
		if (*str <= 'z' && *str >= 'a')
			++i;
		if (*str <= 'Z' && *str >= 'A')
			++i;
		++str;
	}
	if (len == i)
		return (1);
	else
		return (0);
}

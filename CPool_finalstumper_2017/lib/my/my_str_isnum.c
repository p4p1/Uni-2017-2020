/*
** EPITECH PROJECT, 2017
** my_str_isnum.c
** File description:
** 1 if str is a number
*/

int my_str_isnum(char const *str)
{
	int	len = 0;
	int	i = 0;

	if (str == 0)
		return (1);
	while (*(str+len) != '\0')
		len++;
	while(*str != '\0') {
		if (*str <= '9' && *str >= '0')
			i++;
		str++;
	}
	if (len == i)
		return (1);
	else if (len == 0)
		return (1);
	else
		return (0);
}

/*
** EPITECH PROJECT, 2017
** my_str_isprintable.c
** File description:
** return 1 if str is printable
*/

int my_str_isprintable(char const *str)
{
	int	len = 0;
	int	i = 0;

	if (str == 0)
		return (0);
	while (*(str+len) != '\0')
		len++;
	while (*str != '\0') {
		if (*str <= '~' && *str >= ' ')
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

/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** Return the size of str
*/

void my_putchar(char c);

int my_strlen(char const *str)
{
	int	len = 0;

	if (str == 0)
		return (-1);
	while (*str++ != '\0')
		len++;
	return (len);
}

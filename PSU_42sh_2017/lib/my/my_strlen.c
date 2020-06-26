/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** strlen
*/

int my_strlen(char const *str)
{
	int i = 0;

	if (!str)
		return (0);
	while ( *str != '\0') {
		i ++;
		str ++;
	}
	return (i);
}

/*
** EPITECH PROJECT, 2017
** my_strlowcase.c
** File description:
** set to lowcase all upcase chars
*/

char *my_strlowcase(char *str)
{
	int	i = 0;

	if (str == 0)
		return (0);
	while (*(str+i) != '\0') {
		if (*(str+i) >= 'A' && *(str+i) <= 'Z')
			*(str+i) = *(str+i) + 32;
		++i;
	}
	return (str);
}

/*
** EPITECH PROJECT, 2017
** my_strncpy.c
** File description:
** copy string to destination.
*/

int get_len_src(char const *src)
{
	int	len = 0;

	while (*(src+len) != '\0')
		len++;
	return (len);
}

char *my_strncpy(char *dest, char const *src, int n)
{
	int	i = 0;
	int	s_len = get_len_src(src);

	while (*src != '\0' && i < n) {
		*(dest+i) = *src++;
		++i;
	}
	if (n < s_len)
		*(dest+(i)) = '\0';
	return (dest);
}

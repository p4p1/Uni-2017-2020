/*
** EPITECH PROJECT, 2017
** my_strncat
** File description:
** <..>
*/

void my_putchar(char c);

int get_src_len_strncat(char const *str)
{
	int	len = 0;

	while (*(str+len) != '\0')
		len++;
	return (len);
}

char *my_strncat(char *dest, char const *src, int n)
{
	int	i = 0;
	int	c = 0;

	if (n < 0)
		n = get_src_len_strncat(src);
	while (*(dest+c) != '\0')
		c++;
	while (*(src+i) != '\0' && i < n) {
		*(dest+(c+i)) = *(src+i);
		++i;
	}
	*(dest+(c+i+1)) = '\0';
	return (dest);
}

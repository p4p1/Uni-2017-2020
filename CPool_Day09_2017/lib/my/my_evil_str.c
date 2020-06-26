/*
** EPITECH PROJECT, 2017
** my_evil_str
** File description:
** my_evil_str ex
*/

void my_putchar(char c);

char *my_evil_str(char *str)
{
	char	tmp = 0;
	char	len = 0;
	char	i = 0;

	if (str == 0)
		return(0);
	while (*(str+len) != '\0')
		len++;
	len--;
	while (i <= (len / 2)) {
		tmp = *(str+(len-i));
		*(str+(len-i)) = *(str+i);
		*(str+i) = tmp;
		i++;
	}
	return (str);
}

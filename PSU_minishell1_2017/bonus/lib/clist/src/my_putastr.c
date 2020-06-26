/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** write a string on stdout
*/

void my_putachar(char c);

int my_putastr(char const *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (-1);
	while (*(str+i) != '\0')
		my_putachar(*(str+i++));
	return (0);
}

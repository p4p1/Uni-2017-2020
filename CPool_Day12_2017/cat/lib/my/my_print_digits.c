/*
** EPITECH PROJECT, 2017
** my_print_digits
** File description:
**	the my_print_digits ex
*/

void my_putchar(char c);

int my_print_digits(void)
{
	char	ch = '0';

	while (ch <= '9')
		my_putchar(ch++);
	return (0);
}

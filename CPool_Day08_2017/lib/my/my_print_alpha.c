/*
** EPITECH PROJECT, 2017
** my_print_alpha
** File description:
**	Print the alphabet
*/

void my_putchar(char c);

int my_print_alpha(void)
{
	char	ch = 'a';

	while (ch <= 'z')
		my_putchar(ch++);
	return (0);
}

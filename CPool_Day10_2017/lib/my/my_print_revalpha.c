/*
** EPITECH PROJECT, 2017
** my_print_revalpah
** File description:
** the my_print_revalpha ex
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
	char	ch = 'z';

	while (ch >= 'a')
		my_putchar(ch--);
	return (0);
}

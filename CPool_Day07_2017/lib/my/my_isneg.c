/*
** EPITECH PROJECT, 2017
** my_isneg
** File description:
** my_isneg function that write on stdout N for negative numbers
** and P for positive numbers.
*/

void my_putchar(char c);

int my_isneg(int n)
{
	if (n < 0)
		my_putchar('N');
	else
		my_putchar('P');
	return (0);
}

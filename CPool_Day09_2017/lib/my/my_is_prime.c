/*
** EPITECH PROJECT, 2017
** my_is_prime
** File description:
** Check if no is prime or not
*/

void my_putchar(char c);

int my_is_prime(int nb)
{
	int	i = 2;
	int	flag = 0;

	while (i <= nb/2)
		if (nb % i++ == 0)
			flag = 1;
	if (flag)
		return (0);
	else
		return (1);
}

/*
** EPITECH PROJECT, 2017
** my_find_prime_sup
** File description:
** find the superior prime no
*/

void my_putchar(char c);

int is_p(int nb)
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

int my_find_prime_sup(int nb)
{
	int	i = 0;
	int	pnb = 0;

	while (!(pnb > nb)) {
		if (is_p(i))
			pnb = i;
		i++;
	}
	return (pnb);
}

/*
** EPITECH PROJECT, 2017
** my_compute_power_it
** File description:
** put a no to the power of p
*/

void my_putchar(char c);

int my_compute_power_it(int nb, int p)
{
	int	nb_p = 1;
	int	i = 0;

	if (p == 0)
		return (1);
	else if (p < 0)
		return (0);
	while (i++ < p)
		nb_p *= nb;
	return (nb_p);
}

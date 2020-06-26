/*
** EPITECH PROJECT, 2017
** my_compute_power_rec
** File description:
** power of n but in recursive
*/

void my_putchar(char c);

int my_compute_power_rec(int nb, int p)
{
	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	else
		return (nb * my_compute_power_rec(nb, p-1));
}

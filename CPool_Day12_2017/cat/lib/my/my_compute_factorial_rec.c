/*
** EPITECH PROJECT, 2017
** my_compute_factorial_rec
** File description:
** factorial function but recursive
*/

void my_putchar(char c);

int my_compute_factorial_rec(int nb)
{
	if (nb < 0)
		return (0);
	if (nb >= 1)
		return (nb *my_compute_factorial_rec(nb-1));
	else
		return (1);
}

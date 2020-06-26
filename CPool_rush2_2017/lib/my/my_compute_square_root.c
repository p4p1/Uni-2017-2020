/*
** EPITECH PROJECT, 2017
** my_compute_square_root
** File description:
** put to the square root
*/

void my_putchar(char c);

int my_compute_square_root(int nb)
{
	int	i = -1;

	while (++i < nb) {
		if (nb == i*i)
			return (i);
	}
	return (0);
}

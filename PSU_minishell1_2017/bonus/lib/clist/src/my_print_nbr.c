/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
**   the my_put_nbr ex
*/

#include <unistd.h>

void my_putachar(char c)
{
	write(1, &c, 1);
}

int prnb_number_len(int nb)
{
	int	len = 0;
	int	n;

	if (nb == 0)
		return (1);
	n = nb;
	while (n != 0) {
		n /= 10;
		len++;
	}
	return (len);
}

int prnb_get_digit(int nb, int loc)
{
	int	size;
	int	i = 0;

	if (nb == 0)
		return (0);
	size = prnb_number_len(nb) - (loc + 1);
	while (i++ < size)
		nb /= 10;
	return (nb % 10);
}

int prnb_invert_sign(int nb)
{
	if (nb < -2147483647)
		nb--;
	return (nb *= -1);
}

int my_print_nbr(int nb)
{
	int	len;
	int	i = 0;
	int	flag = 0;

	len = prnb_number_len(nb);
	if (nb < 0) {
		my_putachar('-');
		if (nb++ == -2147483648) {
			flag++;
			len--;
		}
		nb *= -1;
	}
	while (i < len)
		my_putachar(prnb_get_digit(nb, i++) + '0');
	if (flag)
		my_putachar('8');
	return (0);
}


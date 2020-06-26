/*
** EPITECH PROJECT, 2017
** my_putnbr_base.c
** File description:
**
*/

int pnb_number_len(int nb)
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

int pnb_get_digit(int nb, int loc)
{
	int	size;
	int	i = 0;

	if (nb == 0)
		return (0);
	size = pnb_number_len(nb) - (loc + 1);
	while (i++ < size)
		nb /= 10;
	return (nb % 10);
}

int find_power(int nb, char const *base)
{
	int	pos = 0;

	while (*(base+pos) != (nb+'0')) {
		pos++;
	}
	return (0);
}

int my_putnbr_base(int nb, char const *base)
{
	int	len = 0;

	while (*(base+len) != '\0')
		len ++;
	return (nb);
}

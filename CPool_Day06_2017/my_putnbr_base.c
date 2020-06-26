/*
** EPITECH PROJECT, 2017
** my_putnbr_base.c
** File description:
**
*/

void my_putchar(char c);

int pnb_base_number_len(int nb)
{
	int	len = 0;
	int	n = nb;

	while (n != 0) {
		n /= 10;
		len++;
	}
	return (len);
}

int my_putnbr_base(int nbr, char const *base)
{
	int	pos = 0;
	int	nb_len = 0;
	int	i = 0;

	if (base == 0)
		return (0);
	while(*(base+nb_len) != '\0')
		nb_len++;
	while (nbr > 0) {
		pos = nbr % nb_len;
		my_putchar(*(base+pos));
		nbr /= nb_len;
	}
	return (0);
}


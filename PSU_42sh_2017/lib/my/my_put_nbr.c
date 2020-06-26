/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** important askip
*/

#include "./../../include/my.h"

int my_put_nbr(int nb)
{
	int resultat1 = 0;
	int resultat = 0;

	if (nb >= 0) {
		if (nb <= 9) {
			resultat = (nb + 48);
		} else {
			resultat = ((nb % 10) + 48);
			resultat1 = (nb / 10);
			my_put_nbr((resultat1));
		}
		my_putchar(resultat);
	} else  if (nb == -2147483648) {
		my_putstr("-2147483648");
	} else {
		my_putchar('-');
		nb *= -1;
		my_put_nbr(nb);
	}
	return (0);
}

/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** get nbr
*/

#include "./../../include/my.h"

int my_getnbr(char const *str)
{
	int i = 0;
	int nb = 0;
	int compteur = 0;

	while (str[i] < 48 ||  str[i] > 57) {
		if (str[i] == '-')
			compteur ++;
		if (str[i] == '\0')
			return (0);
		i ++;
	}
	while (str[i] != '\0') {
		if (48 <= str[i] &&  str[i] <= 57)
			nb = (nb * 10) + (str[i] - 48);
		if ( str[i] > 57 || str[i] < 48){
			return ((compteur > 0) ? -nb : nb);
		}
		i ++;
	}
	return ((compteur > 0) ? -nb : nb);
}

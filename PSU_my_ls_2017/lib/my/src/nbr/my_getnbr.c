/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** my_getnbr ex.
*/

#include "my.h"

static int scan_no(char *str, int i)
{
	int	nb = 0;

	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
		nb = (nb + (str[i] - '0')) * 10;
		i = i + 1;
	}
	return (nb);
}

int my_getnbr(char *str)
{
	int	nb = 0;
	int	i = 0;
	int	flag = 0;

	if (str == 0)
		return (-1);
	if (str[i] == '-')
		flag = 1;
	nb = scan_no(str, i);
	return ((flag == 1) ? ((0 - nb) / 10) : (nb / 10));
}

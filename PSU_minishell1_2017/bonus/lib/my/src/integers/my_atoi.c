/*
** EPITECH PROJECT, 2017
** my_atoi.c
** File description:
** <..>
*/

#include <stdio.h>

int my_atoi(const char *nptr)
{
	long long int	no = 0;
	int		neg = 1;

	if (*nptr == '-')
		neg = ',' - *nptr++;
	while (*nptr != '\0') {
		if (*nptr <= '9' && *nptr >= '0') {
			no = (*nptr - '0') + (no * 10);
		} else {
			break;
		}
		nptr++;
	}
	no *= neg;
	if (no > 2147483647 || no < -2147483648)
		return (0);
	return (no);
}

int main(void)
{
	printf ("%d\n", my_atoi("18446744073709551615"));
	printf ("%d\n", my_atoi("8589934588"));
	printf ("%d\n", my_atoi("-0"));
	printf ("%d\n", my_atoi("0"));
	printf ("%d\n", my_atoi("-1"));
	printf ("%d\n", my_atoi("-2147483648"));
}

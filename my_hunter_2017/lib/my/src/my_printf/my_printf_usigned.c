/*
** EPITECH PROJECT, 2017
** my_printf_usigned.c
** File description:
** unsigned function for my_printf
*/

#include "my_printf.h"

int my_printf_u(va_list arg, char *args)
{
	int	i = 0;
	unsigned int	str = va_arg(arg, unsigned int);

	my_put_nbr(str);
	while (str != 0) {
		str /= 10;
		i++;
	}
	args++;
	return (i);
}

int my_printf_o(va_list arg, char *args)
{
	int	i = 0;
	unsigned int	str = va_arg(arg, unsigned int);

	my_putnbr_base(str, "01234567");
	while (str != 0) {
		str /= 10;
		i++;
	}
	args++;
	return (i);
}

int my_printf_x(va_list arg, char *args)
{
	int	i = 0;
	unsigned int	str = va_arg(arg, unsigned int);

	my_putnbr_base(str, "0123456789abcdef");
	while (str != 0) {
		str /= 10;
		i++;
	}
	args++;
	return (i);
}

int my_printf_X(va_list arg, char *args)
{
	int	i = 0;
	unsigned int	str = va_arg(arg, unsigned int);

	my_putnbr_base(str, "0123456789ABCDEF");
	while (str != 0) {
		str /= 10;
		i++;
	}
	args++;
	return (i);
}

int my_printf_b(va_list arg, char *args)
{
	int	i = 0;
	unsigned int	str = va_arg(arg, unsigned int);

	my_putnbr_base(str, "01");
	while (str != 0) {
		str /= 10;
		i++;
	}
	args++;
	return (i);
}

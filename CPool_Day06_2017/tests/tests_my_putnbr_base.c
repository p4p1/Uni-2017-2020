/*
** EPITECH PROJECT, 2017
** tests_my_putnbr_base.c
** File description:
** test file for my_putnbr base
*/

#include <criterion/criterion.h>

int my_putnbr_base(int nbr, char const *base);

Test(my_putnbr_base, testing_putnbr_base)
{
	my_putnbr_base(255, "0123456789ABCDEF");
	my_putnbr_base(1024, "01");
}

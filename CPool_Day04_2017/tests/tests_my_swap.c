/*
** EPITECH PROJECT, 2017
** my_swap
** File description:
** <..>
*/
#include <criterion/criterion.h>

void my_swap(int *a, int *b);

Test(my_swap, str_are_equal)
{
	int	a = 35;
	int	b = 11;

	my_swap(&a, &b);
	cr_assert_eq(a, 11);
	cr_assert_eq(b, 35);
}


/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** <..>
*/
#include <criterion/criterion.h>

int my_getnbr(char const *str);

Test(my_get_nbr, ret_value_equV1)
{
	cr_assert_eq(my_getnbr("42a43"), 42);
	cr_assert_eq(my_getnbr("42-45"), 42);
	cr_assert_eq(my_getnbr("+----+++__--------+-42"), -42);
	cr_assert_eq(my_getnbr("--42"), 42);
	cr_assert_eq(my_getnbr("10000000000000000000000001421"), 0);
	cr_assert_eq(my_getnbr("000000000000042"), 42);
	cr_assert_eq(my_getnbr("-2147483648"), -2147483648);
	cr_assert_eq(my_getnbr("2147483647"), 2147483647);
}

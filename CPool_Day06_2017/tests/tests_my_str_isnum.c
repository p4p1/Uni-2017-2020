/*
** EPITECH PROJECT, 2017
** tests_my_str_isnum.c
** File description:
** testing my_str_isnum.c
*/

#include <criterion/criterion.h>

int my_str_isnum(char const *str);

Test(my_str_isnum, test_str_num_v1)
{
	cr_assert_eq(my_str_isnum("12345"), 1);
	cr_assert_eq(my_str_isnum("12dfsk345"), 0);
	cr_assert_eq(my_str_isnum(""), 1);
}
